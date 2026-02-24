// /inherit/user/gmcp.c
// GMCP Apply Module for Player Objects
//
// Watches dbase for source mapping changes (skillmix, yuanshen, etc.)
// and tmp_dbase for temp buff changes (buff/, apply/, bonus/).
// Watches feature/skill.c mappings for skill data changes.
// Sends raw source data — GUI computes totals client-side.

#ifndef GMCP_D
#define GMCP_D "/adm/daemons/gmcp_d"
#endif

// Forward declarations
void __gmcp_watch_item(object ob);
void __gmcp_schedule_inventory();
void __gmcp_schedule_skills();

// Keys that trigger Char.Vitals push
nosave string *VITALS_KEYS = ({
    "jing", "eff_jing", "max_jing",
    "qi", "eff_qi", "max_qi",
    "jingli", "max_jingli", "eff_jingli", "jiajing",
    "neili", "max_neili", "jiali",
    "food", "water",
    "potential", "learned_points",
    "experience", "learned_experience",
    "combat_exp", "jianu",
});

// Keys that trigger Char.Status push
nosave string *STATUS_KEYS = ({
    "str", "int", "con", "dex", "per", "kar",
    "level",
    "ability", "achievement", "active",
    "xuemai_level", "yuanshen_level",
    "combat_exp", "special_skill", "xuemai",
    "die_protect", "no_newbie", "newbie",
    "yuanshen_exp", "energy", "learned_energy",
    "gift", "jm", "ys",
});

// Top-level dbase keys whose changes trigger Char.Buffs push
// These are the raw buff source mappings
nosave string *BUFFS_DBASE_KEYS = ({
    "skillmix", "yuanshen", "jingmai",
    "ability1", "ability2", "talent",
});

// Top-level tmp_dbase keys that affect buff display
// "buff_cache" deletion means equipment buffs changed
nosave string *BUFFS_TMP_KEYS = ({
    "buff", "apply", "bonus", "buff_cache",
});

// Keys that trigger Char.Talents push
nosave string *TALENTS_KEYS = ({
    "talent", "talent_count", "energy", "learned_energy",
});

// Top-level tmp_dbase keys that indicate equipment changes
// "buff_cache" is deleted by reset_buff_cache() on every equip/unequip
nosave string *EQUIP_TMP_KEYS = ({
    "weapon", "secondary_weapon", "handing", "fullsuit", "buff_cache",
});

nosave int __gmcp_watch_active = 0;
nosave int __gmcp_vitals_pending = 0;
nosave int __gmcp_status_pending = 0;
nosave int __gmcp_buffs_pending = 0;
nosave int __gmcp_inventory_pending = 0;
nosave int __gmcp_skills_pending = 0;
nosave int __gmcp_talents_pending = 0;

// Track whether we've set up skill mapping watches
nosave int __gmcp_skills_watch_active = 0;

// Track which item dbase mappings we've already watched
// key = file_name(ob), value = item's dbase mapping reference
nosave mapping __gmcp_watched_items = ([]);

// ——— Called by GMCP_D to actually send data ———
void receive_gmcp(string payload) {
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    efun::send_gmcp(payload);
}

// ——— Deferred sends (coalesce multiple changes in same frame) ———
void __gmcp_flush_vitals() {
    object gd;

    __gmcp_vitals_pending = 0;
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_vitals(this_object());
}

void __gmcp_flush_status() {
    object gd;

    __gmcp_status_pending = 0;
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_status(this_object());
}

void __gmcp_flush_buffs() {
    object gd;

    __gmcp_buffs_pending = 0;
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_buffs(this_object());
}

void __gmcp_flush_skills() {
    object gd;

    __gmcp_skills_pending = 0;
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_skills(this_object());
}

void __gmcp_flush_talents() {
    object gd;

    __gmcp_talents_pending = 0;
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_talents(this_object());
}

void __gmcp_flush_inventory() {
    object gd;

    __gmcp_inventory_pending = 0;
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_inventory(this_object());
}

// ——— Schedule a deferred skills push ———
void __gmcp_schedule_skills() {
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    if (__gmcp_skills_pending) return;

    __gmcp_skills_pending = 1;
    call_out("__gmcp_flush_skills", 0);
}

// ——— Schedule a deferred inventory push ———
void __gmcp_schedule_inventory() {
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    if (__gmcp_inventory_pending) return;

    __gmcp_inventory_pending = 1;
    call_out("__gmcp_flush_inventory", 0);
}

// ——— Equipment set load (called on player object so force_me has permission) ———
void gmcp_equip_set(int num) {
    if (num < 1 || num > 5) return;
    if (!query("equipment_set/" + num, this_object())) return;
    call_out("__gmcp_do_equip_set", 0, num);
}

void __gmcp_do_equip_set(int num) {
    this_object()->force_me("equip " + num);
}

// ——— Skill mapping watch callback ———
// Fires when skills, learned, skill_map, skill_prepare, or wprepare
// mappings change. watch_mapping on the individual sub-mappings from
// feature/skill.c detects all mutations (improve_skill, map_skill, etc.)
void __gmcp_skill_data_changed(mapping m, mixed *keys, mixed old_val, mixed new_val) {
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    __gmcp_schedule_skills();
}

// Set up watches on the individual skill mappings from feature/skill.c
// These are standalone variables, NOT inside dbase, so we must watch
// them separately from the dbase/tmp_dbase watches.
void __gmcp_setup_skill_watches() {
    mapping skill_data;

    if (__gmcp_skills_watch_active) return;

    skill_data = this_object()->query_SKILL();
    if (!mapp(skill_data)) return;

    // Watch each sub-mapping that exists.
    // watch_mapping works on nested mappings, so watching the top-level
    // sub-mapping catches all key changes within it.

    // skills mapping — changes on learn/practice/improve_skill
    if (mapp(skill_data["skills"]))
        watch_mapping(skill_data["skills"], (: __gmcp_skill_data_changed :));

    // learned mapping — changes on improve_skill (XP accumulation)
    if (mapp(skill_data["learned"]))
        watch_mapping(skill_data["learned"], (: __gmcp_skill_data_changed :));

    // skill_map — changes on enable/jifa command
    if (mapp(skill_data["skill_map"]))
        watch_mapping(skill_data["skill_map"], (: __gmcp_skill_data_changed :));

    // skill_prepare — changes on prepare/bei command
    if (mapp(skill_data["skill_prepare"]))
        watch_mapping(skill_data["skill_prepare"], (: __gmcp_skill_data_changed :));

    // wprepare — weapon prepare
    if (mapp(skill_data["wprepare"]))
        watch_mapping(skill_data["wprepare"], (: __gmcp_skill_data_changed :));

    __gmcp_skills_watch_active = 1;
}

// ——— dbase watch callback ———
void __gmcp_dbase_changed(mapping m, mixed *keys, mixed old_val, mixed new_val) {
    string key;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    if (old_val == new_val) return;

    key = keys[0];

    if (!__gmcp_vitals_pending &&
        member_array(key, VITALS_KEYS) != -1) {
        __gmcp_vitals_pending = 1;
        call_out("__gmcp_flush_vitals", 0);
    }

    if (!__gmcp_status_pending &&
        member_array(key, STATUS_KEYS) != -1) {
        __gmcp_status_pending = 1;
        call_out("__gmcp_flush_status", 0);
    }

    // Buff source mapping changed
    if (!__gmcp_buffs_pending &&
        member_array(key, BUFFS_DBASE_KEYS) != -1) {
        __gmcp_buffs_pending = 1;
        call_out("__gmcp_flush_buffs", 0);
    }

    // Talent data changed
    if (!__gmcp_talents_pending &&
        member_array(key, TALENTS_KEYS) != -1) {
        __gmcp_talents_pending = 1;
        call_out("__gmcp_flush_talents", 0);
    }

    // Equipment set saved/deleted
    if (key == "equipment_set")
        __gmcp_schedule_inventory();
}

// ——— tmp_dbase watch callback ———
// Watches for:
//   buff/apply/bonus → Char.Buffs push
//   weapon/secondary_weapon/handing/fullsuit → Char.Inventory push
void __gmcp_tmp_dbase_changed(mapping m, mixed *keys, mixed old_val, mixed new_val) {
    string key;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    key = keys[0];

    // Buff-related temp changes
    if (member_array(key, BUFFS_TMP_KEYS) != -1) {
        if (!__gmcp_buffs_pending) {
            __gmcp_buffs_pending = 1;
            call_out("__gmcp_flush_buffs", 0);
        }
    }

    // Equipment-related temp changes (equip/unequip/hand)
    if (member_array(key, EQUIP_TMP_KEYS) != -1)
        __gmcp_schedule_inventory();
}

// ——— Register the dbase watches ———
void gmcp_setup_watch() {
    mapping my, tmp;

    if (__gmcp_watch_active) return;

    // Watch persistent dbase for vitals/status/buff-source changes
    // After the _set() patch, nested key sets (e.g. "equipment_set/3")
    // also trigger this watch via top-level key re-assignment
    my = this_object()->query_entire_dbase();
    if (my)
        watch_mapping(my, (: __gmcp_dbase_changed :));

    // Watch tmp_dbase for temp buff changes
    tmp = this_object()->query_entire_temp_dbase();
    if (tmp)
        watch_mapping(tmp, (: __gmcp_tmp_dbase_changed :));

    __gmcp_watch_active = 1;
}

// ——— Delayed Initial Data Push ———
void gmcp_init_burst() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    if (!this_object()->is_user()) return;

    gmcp_setup_watch();

    // Set up skill data watches (separate from dbase)
    __gmcp_setup_skill_watches();

    // Watch all existing inventory items' dbase for changes
    foreach (object ob in all_inventory(this_object())) {
        if (objectp(ob))
            __gmcp_watch_item(ob);
    }

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (!gd) return;

    gd->send_info(this_object());
    gd->send_vitals(this_object());
    gd->send_status(this_object());
    gd->send_buffs(this_object());
    gd->send_skills(this_object());
    gd->send_talents(this_object());
    gd->send_inventory(this_object());
    gd->send_channels(this_object());
    gd->send_room(this_object());

    // Graph Map: pre-index current room for fast Map.Hello response
#ifdef GRAPH_MAP_D
    {
        object map_d;
        map_d = find_object(GRAPH_MAP_D);
        if (!map_d) map_d = load_object(GRAPH_MAP_D);
        if (map_d) map_d->on_player_login(this_object());
    }
#endif
}

// ——— Item movement detection ———

// Callback when any watched item's dbase changes
void __gmcp_item_dbase_changed(mapping m, mixed *keys, mixed old_val, mixed new_val) {
    // The item's dbase changed — schedule inventory push
    // if this player is still interactive with GMCP.
    // (We can't unwatch, so stale watches just no-op here.)
    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;
    __gmcp_schedule_inventory();
}

// Watch an item's dbase for changes (e.g. equipped, enchase, etc.)
void __gmcp_watch_item(object ob) {
    mapping item_db;
    string key;

    if (!objectp(ob)) return;

    key = file_name(ob);
    if (__gmcp_watched_items[key]) return;

    item_db = ob->query_entire_dbase();
    if (!mapp(item_db)) return;

    watch_mapping(item_db, (: __gmcp_item_dbase_changed :));
    __gmcp_watched_items[key] = item_db;  // store ref for unwatch
}

// Unwatch an item's dbase when it leaves inventory
void __gmcp_unwatch_item(object ob) {
    mapping item_db;
    string key;

    if (!objectp(ob)) return;

    key = file_name(ob);
    item_db = __gmcp_watched_items[key];
    if (!mapp(item_db)) return;

    unwatch_mapping(item_db, (: __gmcp_item_dbase_changed :));
    map_delete(__gmcp_watched_items, key);
}

// Called from move.c when an object enters this player's inventory
void gmcp_receive_object(object ob) {
    if (!objectp(ob)) return;
    __gmcp_watch_item(ob);
    __gmcp_schedule_inventory();
}

// Called from move.c when an object leaves this player's inventory
void gmcp_release_object(object ob) {
    if (!objectp(ob)) return;
    __gmcp_unwatch_item(ob);
    __gmcp_schedule_inventory();
}

// ——— Driver Apply: gmcp ———
void gmcp(string message) {
    object gd;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (!gd) return;

    gd->handle_gmcp(this_object(), message);
}

// ——— Public API ———
void gmcp_update_vitals() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_vitals(this_object());
}

void gmcp_update_status() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_status(this_object());
}

void gmcp_update_buffs() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_buffs(this_object());
}

void gmcp_update_room() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_room(this_object());
}

void gmcp_update_inventory() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_inventory(this_object());
}

void gmcp_update_skills() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_skills(this_object());
}

void gmcp_chat(string channel, string speaker, string message) {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_chat(this_object(), channel, speaker, message);
}

void gmcp_update_channels() {
    object gd;

    if (!interactive(this_object())) return;
    if (!has_gmcp(this_object())) return;

    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (gd) gd->send_channels(this_object());
}

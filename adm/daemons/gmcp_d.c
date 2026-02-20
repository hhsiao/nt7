// /adm/daemons/gmcp_d.c
// GMCP Daemon — ALL variable declarations at function top (FluffOS C89-style)

#include <ansi.h>

#ifndef GMCP_D
#define GMCP_D "/adm/daemons/gmcp_d"
#endif

// ——— Forward declarations ———
void gmcp_send(object who, string package, mixed data);

// ——— GUI Package Auto-Install Config ———
// Mudlet will auto-install/update the package when version changes.
// Set via: GMCP_D->set_gui_url("http://yourhost:port/static/WuxiaGUI3.mpackage")
// Set via: GMCP_D->set_gui_version("1.0.0")

nosave string gui_url     = "http://localhost:8888/static/WuxiaGUI3.mpackage";
nosave string gui_version = "1.0.0";

void set_gui_url(string url)     { if (stringp(url)) gui_url = url; }
void set_gui_version(string ver) { if (stringp(ver)) gui_version = ver; }
string query_gui_url()           { return gui_url; }
string query_gui_version()       { return gui_version; }

// Send Client.GUI to trigger Mudlet auto-install/update
void send_gui(object who) {
    if (!who || !interactive(who) || !has_gmcp(who)) return;
    if (!gui_url || gui_url == "") return;

    gmcp_send(who, "Client.GUI", ([
        "version" : gui_version,
        "url"     : gui_url,
    ]));
}

// ——— JSON helpers ———
// Using native FluffOS yyjson: json_encode() and json_decode()
// No custom implementations needed.

// Legacy wrapper kept for any external callers
string to_json(mixed val) {
    return json_encode(val);
}

mapping parse_json_object(string s) {
    mixed result;

    if (!stringp(s) || s == "") return ([]);
    result = json_decode(s);
    if (!mapp(result)) return ([]);
    return result;
}

// ——— Core Send ———

void gmcp_send(object who, string package, mixed data) {
    string payload;

    if (!who || !interactive(who) || !has_gmcp(who)) return;
    payload = package + " " + json_encode(data);
    who->receive_gmcp(payload);
}

// ——— Helper: extract integer-valued keys from a mapping ———
// Filters out sub-mappings and non-integer values, returns
// a clean mapping of string->int suitable for JSON.

mapping extract_int_map(mapping src) {
    mapping result;

    result = ([]);
    if (!mapp(src)) return result;

    foreach (string k in keys(src)) {
        if (intp(src[k]))
            result[k] = src[k];
    }
    return result;
}

// ——— Char.Skills ———
// Sends raw skill data (skills, learned, skill_map, skill_prepare, wprepare)
// plus a computed mapping with server-only data per skill (name, type).
//
// Design: raw mappings are sent as-is (rule: send all data, no copies).
// computed contains only data that requires server-side SKILL_D calls
// and cannot be derived client-side.
//
// Effective level is computed CLIENT-SIDE using:
//   buff(skill) from Char.Buffs temp[skill]
//   add_skill from Char.Buffs temp["add_skill"]
//   raw level from skills[id]
//   mapped skill from skill_map[id] -> skills[mapped_id]
//   Formula: buff + (add_skill + raw) / 2 + (add_skill + mapped_raw)
//
// Payload:
// {
//   "skills":        { "force": 130, "hamagong": 130, ... },
//   "learned":       { "force": 0, ... },
//   "skill_map":     { "force": "hamagong", ... },
//   "skill_prepare": { "cuff": "lingshe-quan", ... },
//   "wprepare":      { ... },
//   "computed": {
//     "force":    { "name": "基本內功", "type": "martial" },
//     "hamagong": { "name": "蛤蟆功",  "type": "martial" },
//     ...
//   }
// }

void send_skills(object who) {
    mapping data, skl, lrn, smap, sprep, wprep, computed;
    mapping skill_data, entry;
    string *snames, sk, type, chi_name;
    object skill_ob;
    int i;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    // Get raw skill data from feature/skill.c
    skill_data = who->query_SKILL();
    if (!mapp(skill_data)) return;

    skl   = skill_data["skills"];
    lrn   = skill_data["learned"];
    smap  = skill_data["skill_map"];
    sprep = skill_data["skill_prepare"];
    wprep = skill_data["wprepare"];

    if (!mapp(skl) || !sizeof(skl)) {
        // Player has no skills yet — send empty
        gmcp_send(who, "Char.Skills", ([
            "skills":        ([]),
            "learned":       ([]),
            "skill_map":     ([]),
            "skill_prepare": ([]),
            "wprepare":      ([]),
            "computed":      ([]),
        ]));
        return;
    }

    // Build computed data for each skill (server-only: name + type)
    snames = keys(skl);
    computed = ([]);

    for (i = 0; i < sizeof(snames); i++) {
        sk = snames[i];
        entry = ([]);

        // Chinese name via to_chinese (CHINESE_D)
        chi_name = to_chinese(sk);
        entry["name"] = stringp(chi_name) ? chi_name : sk;

        // Skill type from SKILL_D
        skill_ob = find_object(SKILL_D(sk));
        if (!skill_ob) skill_ob = load_object(SKILL_D(sk));
        if (skill_ob) {
            type = skill_ob->type();
            entry["type"] = stringp(type) ? type : "unknown";
        } else {
            entry["type"] = "unknown";
        }

        computed[sk] = entry;
    }

    // Assemble payload — raw mappings sent directly, no copies
    data = ([]);
    data["skills"]        = skl;
    data["learned"]       = mapp(lrn) ? lrn : ([]);
    data["skill_map"]     = mapp(smap) ? smap : ([]);
    data["skill_prepare"] = mapp(sprep) ? sprep : ([]);
    data["wprepare"]      = mapp(wprep) ? wprep : ([]);
    data["computed"]      = computed;

    gmcp_send(who, "Char.Skills", data);
}

// ——— Char.Vitals ———

void send_vitals(object who) {
    mapping my, data;
    int craze;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;
    if (my["max_jing"] < 1 || my["max_qi"] < 1) return;

    data = ([
        "jing":         my["jing"],
        "eff_jing":     my["eff_jing"],
        "max_jing":     my["max_jing"],
        "qi":           my["qi"],
        "eff_qi":       my["eff_qi"],
        "max_qi":       my["max_qi"],
        "jingli":       my["jingli"],
        "max_jingli":   my["max_jingli"],
        "jiajing":      my["jiajing"],
        "neili":        my["neili"],
        "max_neili":    my["max_neili"],
        "jiali":        my["jiali"],
        "food":         my["food"],
        "max_food":     (int)who->max_food_capacity(),
        "water":        my["water"],
        "max_water":    (int)who->max_water_capacity(),
        "potential":    my["potential"] - my["learned_points"],
        "experience":   my["experience"] - my["learned_experience"],
        "combat_exp":   my["combat_exp"],
    ]);

    craze = (int)who->query_craze();
    if (craze > 0) {
        data["craze"]     = craze;
        data["max_craze"] = (int)who->query_max_craze();
        data["jianu"]     = my["jianu"];
        data["is_most_craze"] = (int)who->is_most_craze();
    } else {
        data["craze"]     = 0;
        data["max_craze"] = 0;
        data["jianu"]     = 0;
    }

    gmcp_send(who, "Char.Vitals", data);
}

// ——— Char.Status ———

void send_status(object who) {
    mapping my, data;
    int exp, wugong_level, lv, next_level_exp, lv2;
    int max_jiali, max_jianu, need2;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;

    exp = my["combat_exp"] / 100;
    wugong_level = to_int(pow(to_float(exp), 1.0 / 3) * 10) + 1;
    lv = my["level"];
    if (lv < 1) lv = 1;
    next_level_exp = (lv + 1) * (lv + 1) * (lv + 1) * 10000 - my["combat_exp"];
    if (next_level_exp < 1) next_level_exp = 1;

    // Max jiali (from hp -m logic)
    max_jiali = (int)who->query_skill("force") / 2;
    if (mapp(my["special_skill"]) && my["special_skill"]["might"])
        max_jiali += max_jiali * 20 / 100;
    max_jiali += (int)who->query_all_buff("jiali");

    // Max jianu (from hp -m logic)
    if (mapp(my["special_skill"]) && my["special_skill"]["wrath"])
        max_jianu = (int)who->query_max_craze() / 70;
    else
        max_jianu = (int)who->query_max_craze() / 100;
    if (max_jianu < 0) max_jianu = 0;

    // Yuanshen progress (from hp -m logic)
    lv2 = (int)my["yuanshen_level"];
    if (lv2 < 1)
        need2 = 10000000000 - my["combat_exp"];
    else if (lv2 == 100)
        need2 = 0;
    else
        need2 = (lv2 + 1) * (lv2 + 1) * (lv2 + 1) * 10000 - (int)my["yuanshen_exp"];

    data = ([
        "name":         who->name(1),
        "id":           my["id"],
        "title":        my["title"] || "",
        "age":          my["age"],
        "gender":       my["gender"],
        "born":         my["born"] || "",
        "str":          my["str"],
        "int":          my["int"],
        "con":          my["con"],
        "dex":          my["dex"],
        "per":          my["per"],
        "kar":          my["kar"],
        "level":        lv,
        "wugong_level": wugong_level,
        "combat_exp":   my["combat_exp"],
        "next_level":   next_level_exp,
        "jingli_limit":     (int)who->query_current_jingli_limit(),
        "neili_limit":      (int)who->query_current_neili_limit(),
        "potential_limit":  (int)who->query_potential_limit() - my["learned_points"],
        "experience_limit": (int)who->query_experience_limit() - my["learned_experience"],
        "ability":      my["ability"],
        "achievement":  my["achievement"],
        "active":       my["active"],
        "xuemai_level": my["xuemai_level"],
        "yuanshen_level": my["yuanshen_level"],
        "raw_potential":    my["potential"],
        "learned_points":   my["learned_points"],
        "raw_experience":   my["experience"],
        "learned_experience": my["learned_experience"],
        "max_jiali":        max_jiali,
        "max_jianu":        max_jianu,
        "xuemai_progress":  mapp(my["xuemai"]) ? 100 - (int)my["xuemai"]["points"] : 100,
        "yuanshen_next":    need2,
        "death_protect":    (!mapp(my["combat"]) || !my["combat"]["WPK"]) &&
                            !my["no_newbie"] &&
                            (my["newbie"] || my["combat_exp"] < 20000000) ? 1 : 0,
        "kill_protect":     (mapp(my["die_protect"]) &&
                            (int)my["die_protect"]["last_dead"] + (int)my["die_protect"]["duration"] >= time()) ? 1 : 0,
    ]);

    gmcp_send(who, "Char.Status", data);
}

// ——— Char.Buffs ———
// Sends raw source mappings. GUI computes totals client-side.
//
// Payload structure:
// {
//   "skillmix":  { "str": 0, "int": 5, ... },
//   "yuanshen":  { "str": 0, ... },
//   "ability1":  { "str": 0, ... },
//   "ability2":  { "str": 0, ... },
//   "talent":    { "str": 0, ... },
//   "jingmai":   { "str": 180, "int": 180, ..., "finish": 1 },
//   "temp":      { "str": 0, ... }
// }
//
// Equipment is NOT included here (will come with inventory GMCP sync).
// Jingmai: if dbase["jingmai/finish"] is set, sends ZHOUTIAN_D fixed table.
//          Otherwise sends dbase["jingmai"] sub-mapping.

void send_buffs(object who) {
    mapping data, jm, tmp_buff, tmp_apply, tmp_bonus, temp_merged;
    mapping my;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;

    data = ([]);

    // Direct dbase source mappings (filter to int values only)
    data["skillmix"] = extract_int_map(my["skillmix"]);
    data["yuanshen"] = extract_int_map(my["yuanshen"]);
    data["ability1"] = extract_int_map(my["ability1"]);
    data["ability2"] = extract_int_map(my["ability2"]);
    data["talent"]   = extract_int_map(my["talent"]);

    // Jingmai: use fixed ZHOUTIAN_D table if finish flag is set
    jm = my["jingmai"];
    if (mapp(jm) && jm["finish"])
        data["jingmai"] = extract_int_map(
            ZHOUTIAN_D->query_entire_jingmai_data());
    else
        data["jingmai"] = extract_int_map(jm);

    // Temp buffs: merge buff/ + apply/ + bonus/ from tmp_dbase
    // All three are sub-mappings of tmp_dbase keyed by stat name
    tmp_buff  = who->query_entire_temp_dbase()["buff"];
    tmp_apply = who->query_entire_temp_dbase()["apply"];
    tmp_bonus = who->query_entire_temp_dbase()["bonus"];

    temp_merged = ([]);
    if (mapp(tmp_buff)) {
        foreach (string k, mixed v in tmp_buff)
            if (intp(v) && v != 0)
                temp_merged[k] = v;
    }
    if (mapp(tmp_apply)) {
        foreach (string k, mixed v in tmp_apply)
            if (intp(v) && v != 0)
                temp_merged[k] = (temp_merged[k] || 0) + v;
    }
    if (mapp(tmp_bonus)) {
        foreach (string k, mixed v in tmp_bonus)
            if (intp(v) && v != 0)
                temp_merged[k] = (temp_merged[k] || 0) + v;
    }
    data["temp"] = temp_merged;

    gmcp_send(who, "Char.Buffs", data);
}

// ——— Char.Inventory ———
// Sends full inventory + equipment slots + equipment sets + fullsuit data.
//
// Payload:
// {
//   "items": [
//     { "id":"zhufu head", "name":"神之祝福頭盔", "base":"..path..",
//       "slot":"head", "quality":2, "amount":1, "buffs":{"armor":80,"int":2} },
//     { "id":"xian dan", "name":"仙丹", "amount":15 },
//     ...
//   ],
//   "encumbrance": 6,
//   "max_encumbrance": 100,
//   "handing": "item_id_or_null",
//   "secondary": "item_id_or_null",
//   "fullsuit": { "attack":100, "armor":50, ... },
//   "sets": { "1": ["base_name1","base_name2",...], "3": [...] }
// }

void send_inventory(object who) {
    mapping data, computed, my, fullsuit_data, equip_sets, fs_merged, item_dbase;
    object *inv, ob, weapon, sec_weapon, handing;
    mixed *items, *computed_list;
    int enc, max_enc;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;

    inv = all_inventory(who);
    items = ({});
    computed_list = ({});

    weapon     = query_temp("weapon", who);
    sec_weapon = query_temp("secondary_weapon", who);
    handing    = query_temp("handing", who);

    foreach (ob in inv) {
        if (!objectp(ob)) continue;
        if (!who->visible(ob)) continue;

        // Send raw dbase untouched
        item_dbase = ob->query_entire_dbase();
        if (!mapp(item_dbase)) item_dbase = ([]);

        // Server-only computed data goes in a separate mapping
        // keyed by index, NOT mixed into item dbase
        computed = ([]);
        computed["name"]      = ob->name(1) || ob->short() || "???";
        computed["short"]     = ob->short() || "???";
        computed["base_name"] = base_name(ob);

        if (query("equipped", ob)) {
            computed["slot"] = (string)who->query_equipping_part(ob);
            if (ob == sec_weapon)
                computed["equip_status"] = "secondary";
            else
                computed["equip_status"] = "worn";
            if (query_temp("mod_active", ob))
                computed["mod_active"] = 1;
        } else if (ob == handing) {
            computed["equip_status"] = "holding";
        }

        if (function_exists("query_amount", ob) && (int)ob->query_amount() > 1)
            computed["amount"] = (int)ob->query_amount();

        items += ({ item_dbase });
        computed_list += ({ computed });
    }

    data = ([]);
    data["items"] = items;
    data["computed"] = computed_list;

    // Encumbrance
    enc     = (int)who->query_encumbrance();
    max_enc = (int)who->query_max_encumbrance();
    if (max_enc > 0)
        data["encumbrance"] = enc * 100 / max_enc;
    else
        data["encumbrance"] = 0;

    // Handing / secondary weapon IDs
    if (objectp(handing))
        data["handing"] = query("id", handing);
    if (objectp(sec_weapon))
        data["secondary"] = query("id", sec_weapon);

    // Fullsuit bonuses (from player temp data)
    fullsuit_data = query_temp("fullsuit", who);
    if (mapp(fullsuit_data)) {
        fs_merged = ([]);
        foreach (string fs_name, mapping fs_props in fullsuit_data) {
            if (!mapp(fs_props)) continue;
            foreach (string k, mixed v in fs_props) {
                if (intp(v) && v != 0)
                    fs_merged[k] = (fs_merged[k] || 0) + v;
            }
        }
        if (sizeof(fs_merged))
            data["fullsuit"] = fs_merged;
    }

    // Equipment sets
    equip_sets = my["equipment_set"];
    if (mapp(equip_sets)) {
        mapping sets_out;
        sets_out = ([]);
        foreach (string num, mixed arr in equip_sets) {
            if (arrayp(arr))
                sets_out[num] = arr;
        }
        if (sizeof(sets_out))
            data["sets"] = sets_out;
    }

    gmcp_send(who, "Char.Inventory", data);
}

// ——— Char.Info ———

void send_info(object who) {
    mapping data;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    data = ([
        "name":     who->name(1),
        "id":       who->query("id"),
        "title":    who->query("title") || "",
        "server":   "NT7",
    ]);

    gmcp_send(who, "Char.Info", data);
}

// ——— Chat.Line ———

varargs void send_chat(object who, string channel, string speaker,
    string message, string raw_text)
{
    mapping data;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    data = ([
        "channel":  channel,
        "speaker":  speaker,
        "message":  message,
        "time":     time(),
    ]);

    if (stringp(raw_text) && raw_text != "")
        data["raw"] = raw_text;

    gmcp_send(who, "Chat.Line", data);
}

// ——— Chat.Channels ———

void send_channels(object who) {
    mixed *channel_info, *channel_list, *using_ch;
    int my_level, ch_number, ch_level, enabled;
    string ch_cmd;
    mapping data, using_map;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    channel_info = fetch_variable("info", get_object(CHANNEL_D));
    if (!channel_info) return;

    my_level = wiz_level(who->query_id(1));
    channel_list = ({});

    using_ch = CHANNEL_D->query_using_channel(who, 1);
    using_map = ([]);
    if (arrayp(using_ch)) {
        foreach (string cmd in using_ch)
            using_map[cmd] = 1;
    }

    foreach (mixed *c in channel_info) {
        ch_number = c[0];
        ch_level  = c[2];
        ch_cmd    = c[1];
        if (my_level < ch_level) continue;
        enabled = using_map[ch_cmd] ? 1 : 0;
        channel_list += ({ ([ "cmd": ch_cmd, "enabled": enabled ]) });
    }

    data = ([ "channels": channel_list ]);
    gmcp_send(who, "Chat.Channels", data);
}

// ——— Chat.Channels.Tune ———

void handle_tune(object who, string channel_cmd) {
    mixed *channel_info, *using_ch;
    int ch_number, ch_level, my_channels, found, is_using;
    string my_id;

    if (!who || !stringp(channel_cmd)) return;

    channel_info = fetch_variable("info", get_object(CHANNEL_D));
    if (!channel_info) return;

    found = 0;
    foreach (mixed *c in channel_info) {
        if (c[1] == channel_cmd) {
            ch_number = c[0];
            ch_level  = c[2];
            found = 1;
            break;
        }
    }

    if (!found) {
        send_chat(who, "sys", "系統", "沒有這個頻道: " + channel_cmd);
        return;
    }

    my_id = who->query_id(1);

    if (wiz_level(my_id) < ch_level) {
        send_chat(who, "sys", "系統", "沒有這個頻道。");
        return;
    }

    using_ch = CHANNEL_D->query_using_channel(who, 1);
    is_using = 0;
    if (arrayp(using_ch) && member_array(channel_cmd, using_ch) != -1)
        is_using = 1;

    my_channels = who->query("channels");

    if (is_using) {
        who->set("channels", my_channels ^ ch_number);
        CHANNEL_D->remove_register(who, ch_number);
        tell_object(who, "關閉 " + channel_cmd + " 頻道。\n");
    } else {
        who->set("channels", my_channels | ch_number);
        CHANNEL_D->register_channel(who, ch_number);
        tell_object(who, "開啟 " + channel_cmd + " 頻道。\n");
    }

    send_channels(who);
}

// ——— Chat.Channels.Send ———

void handle_chat_send(object who, string channel_cmd, string message) {
    if (!who || !stringp(channel_cmd) || !stringp(message)) return;
    if (message == "") return;
    CHANNEL_D->do_channel(who, channel_cmd, message);
}

// ——— Room.Info ———

void send_room(object who) {
    object env;
    mapping data;
    mixed exits;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    env = environment(who);
    if (!env) return;

    data = ([
        "name":     env->short() || "未知",
        "path":     file_name(env),
    ]);

    exits = env->query("exits");
    if (mapp(exits))
        data["exits"] = keys(exits);

    gmcp_send(who, "Room.Info", data);
}

// ——— Equipment Set Handlers (silent, no console output) ———

// Save current equipment as set N
void handle_equip_save_set(object who, mapping params) {
    string num;
    object *eqs;

    num = params["set"];
    if (!stringp(num) || to_int(num) < 1 || to_int(num) > 5)
        return;

    eqs = who->query_equipment_objects();
    if (!arrayp(eqs) || !sizeof(eqs)) return;

    who->set("equipment_set/" + num,
        map(eqs, (: base_name($1) :)));
    who->save();
}

// Delete set N
void handle_equip_delete_set(object who, mapping params) {
    string num;

    num = params["set"];
    if (!stringp(num) || to_int(num) < 1 || to_int(num) > 5)
        return;

    if (!query("equipment_set/" + num, who)) return;

    who->delete("equipment_set/" + num);
    who->save();
}

// Load set N — delegate to player object for force_me permission
void handle_equip_load_set(object who, mapping params) {
    string num;

    num = params["set"];
    if (!stringp(num) || to_int(num) < 1 || to_int(num) > 5)
        return;

    if (!query("equipment_set/" + num, who)) return;

    who->gmcp_equip_set(to_int(num));
}

// ——— Handle Incoming GMCP ———


// ——— Char.Talents ———
#ifndef ABILITY_D
#define ABILITY_D "/adm/daemons/abilityd"
#endif

void send_talents(object who) {
    mapping my, data;
    mixed *talents;
    string *talent_ids, *talent_infos;
    mapping talent_max, talent_per_lv;
    int i, n, energy, learned_energy, yuanshen_level, max_unlocked;
    object ability_d;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;

    ability_d = find_object(ABILITY_D);
    if (!ability_d) ability_d = load_object(ABILITY_D);
    if (!ability_d) return;

    talent_ids    = ability_d->query_talent_ids();
    talent_infos  = ability_d->query_talent_infos();
    talent_max    = ability_d->query_talent_max();
    talent_per_lv = ability_d->query_talent_per_level();

    if (!arrayp(talent_ids) || !sizeof(talent_ids)) return;

    n = sizeof(talent_ids);
    energy = (int)my["energy"];
    learned_energy = (int)my["learned_energy"];
    yuanshen_level = (int)my["yuanshen_level"];

    // Talents unlock in tiers of 3
    max_unlocked = 0;
    for (i = 0; i < n; i++) {
        if (yuanshen_level >= (i / 3) * 10)
            max_unlocked = i + 1;
    }

    talents = ({});
    for (i = 0; i < n; i++) {
        string id, info_text, name, description;
        int level, max_level, value, per_level, locked, colon_pos;
        mapping talent_entry;

        id = talent_ids[i];
        level = (int)my["talent_count/" + id];
        max_level = talent_max[id] || 5;
        value = (int)my["talent/" + id];
        per_level = talent_per_lv[id] || 0;
        locked = (yuanshen_level < (i / 3) * 10) ? 1 : 0;

        name = id;
        description = "";
        if (arrayp(talent_infos) && i < sizeof(talent_infos)) {
            info_text = talent_infos[i];
            if (stringp(info_text)) {
                colon_pos = strsrch(info_text, "：");
                if (colon_pos > 0) {
                    name = info_text[0..colon_pos - 1];
                    description = info_text[colon_pos + 1..];
                } else {
                    name = info_text;
                }
            }
        }

        talent_entry = ([
            "index":       i + 1,
            "id":          id,
            "name":        name,
            "description": description,
            "level":       level,
            "max_level":   max_level,
            "value":       value,
            "per_level":   per_level,
            "locked":      locked,
        ]);
        talents += ({ talent_entry });
    }

    data = ([
        "energy":         energy,
        "learned_energy": learned_energy,
        "available":      energy - learned_energy,
        "yuanshen_level": yuanshen_level,
        "max_unlocked":   max_unlocked,
        "talents":        talents,
    ]);

    gmcp_send(who, "Char.Talents", data);
}

void handle_gmcp(object who, string raw_message) {
    string package, json_str, ch_cmd, msg;
    int space_pos;
    mapping params;

    if (!who || !stringp(raw_message)) return;

    space_pos = strsrch(raw_message, " ");
    if (space_pos == -1) {
        package = raw_message;
        json_str = "";
    } else {
        package = raw_message[0..space_pos-1];
        json_str = raw_message[space_pos+1..];
    }

    switch (package) {
        case "Core.Hello":
            log_file("gmcp", sprintf("[%s] Core.Hello from %s: %s\n",
                ctime(time()), who->query("id") || "unknown", json_str));
            break;

        case "Core.Supports.Set":
        case "Core.Supports.Add":
            break;

        case "Char.Vitals.Request":
            send_vitals(who);
            break;

        case "Char.Status.Request":
            send_status(who);
            break;

        case "Char.Buffs.Request":
            send_buffs(who);
            break;

        case "Char.Skills.Request":
            send_skills(who);
            break;

        case "Char.Talents.Request":
            send_talents(who);
            break;

        case "Char.Inventory.Request":
            send_inventory(who);
            break;

        case "Char.Inventory.SaveSet":
            params = parse_json_object(json_str);
            if (params)
                handle_equip_save_set(who, params);
            break;

        case "Char.Inventory.DeleteSet":
            params = parse_json_object(json_str);
            if (params)
                handle_equip_delete_set(who, params);
            break;

        case "Char.Inventory.LoadSet":
            params = parse_json_object(json_str);
            if (params)
                handle_equip_load_set(who, params);
            break;

        case "Char.Info.Request":
            send_info(who);
            break;

        case "Room.Info.Request":
            send_room(who);
            break;

        case "Chat.Channels.Request":
            send_channels(who);
            break;

        case "Chat.Channels.Tune":
            params = parse_json_object(json_str);
            ch_cmd = params["channel"];
            if (stringp(ch_cmd))
                handle_tune(who, ch_cmd);
            break;

        case "Chat.Channels.Send":
            params = parse_json_object(json_str);
            ch_cmd = params["channel"];
            msg    = params["message"];
            if (stringp(ch_cmd) && stringp(msg))
                handle_chat_send(who, ch_cmd, msg);
            break;

        default:
            break;
    }
}

void create() {
    seteuid(getuid());
}

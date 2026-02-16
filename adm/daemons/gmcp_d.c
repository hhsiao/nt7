// /adm/daemons/gmcp_d.c
// GMCP Daemon — ALL variable declarations at function top (FluffOS C89-style)

#include <ansi.h>

#ifndef GMCP_D
#define GMCP_D "/adm/daemons/gmcp_d"
#endif

// ─── JSON helpers ───

string json_escape(string s) {
    if (!stringp(s)) return "";
    s = replace_string(s, "\\", "\\\\");
    s = replace_string(s, "\"", "\\\"");
    s = replace_string(s, "\n", "\\n");
    s = replace_string(s, "\t", "\\t");
    s = replace_string(s, "\x1b", "\\u001b");
    s = replace_string(s, "\a", "");   // strip bell
    s = replace_string(s, "\r", "");   // strip CR
    return s;
}

string to_json(mixed val) {
    string *parts;

    if (intp(val))    return "" + val;
    if (floatp(val))  return sprintf("%.2f", val);
    if (stringp(val)) return "\"" + json_escape(val) + "\"";
    if (!val)         return "null";
    if (arrayp(val)) {
        parts = ({});
        foreach (mixed v in val)
            parts += ({ to_json(v) });
        return "[" + implode(parts, ",") + "]";
    }
    if (mapp(val)) {
        parts = ({});
        foreach (mixed k, mixed v in val)
            parts += ({ "\"" + json_escape("" + k) + "\":" + to_json(v) });
        return "{" + implode(parts, ",") + "}";
    }
    return "\"" + json_escape("" + val) + "\"";
}

mapping parse_json_object(string s) {
    mapping result;
    string *pairs;
    string key, val;

    result = ([]);
    if (!stringp(s) || s == "") return result;
    s = trim(s);
    if (s[0] == '{') s = s[1..<2];
    pairs = explode(s, ",");
    foreach (string pair in pairs) {
        if (sscanf(pair, "\"%s\":\"%s\"", key, val) == 2)
            result[key] = val;
        else if (sscanf(pair, "\"%s\":%s", key, val) == 2)
            result[key] = trim(val);
    }
    return result;
}

// ─── Core Send ───

void gmcp_send(object who, string package, mapping data) {
    string payload;

    if (!who || !interactive(who) || !has_gmcp(who)) return;
    payload = package + " " + to_json(data);
    who->receive_gmcp(payload);
}

// ─── Helper: extract integer-valued keys from a mapping ───
// Filters out sub-mappings and non-integer values, returns
// a clean mapping of string->int suitable for JSON.

mapping extract_int_map(mapping src) {
    mapping result;
    mixed v;

    result = ([]);
    if (!mapp(src)) return result;

    foreach (string k in keys(src)) {
        if (intp(src[k]))
            result[k] = src[k];
    }
    return result;
}

// ─── Char.Vitals ───

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

// ─── Char.Status ───

void send_status(object who) {
    mapping my, data;
    int exp, wugong_level, lv, next_level_exp;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;

    exp = my["combat_exp"] / 100;
    wugong_level = to_int(pow(to_float(exp), 1.0 / 3) * 10) + 1;
    lv = my["level"];
    if (lv < 1) lv = 1;
    next_level_exp = (lv + 1) * (lv + 1) * (lv + 1) * 10000 - my["combat_exp"];
    if (next_level_exp < 1) next_level_exp = 1;

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
        "force":        (int)who->query_skill("force"),
        "dodge":        (int)who->query_skill("dodge"),
        "parry":        (int)who->query_skill("parry"),
        "unarmed":      (int)who->query_skill("unarmed"),
        "sword":        (int)who->query_skill("sword"),
        "blade":        (int)who->query_skill("blade"),
        "staff":        (int)who->query_skill("staff"),
        "whip":         (int)who->query_skill("whip"),
        "throwing":     (int)who->query_skill("throwing"),
        "shooting":     (int)who->query_skill("shooting"),
        "literate":     (int)who->query_skill("literate"),
        "martial-arts": (int)who->query_skill("martial-arts"),
        "raw_potential":    my["potential"],
        "learned_points":   my["learned_points"],
        "raw_experience":   my["experience"],
        "learned_experience": my["learned_experience"],
    ]);

    gmcp_send(who, "Char.Status", data);
}

// ─── Char.Buffs ───
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

// ─── Char.Inventory ───
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
    mapping data, item, item_dbase, my, fullsuit_data, equip_sets, fs_merged;
    object *inv, ob, weapon, sec_weapon, handing;
    mixed *items;
    string slot;
    int enc, max_enc;

    if (!who || !interactive(who) || !has_gmcp(who)) return;

    my = who->query_entire_dbase();
    if (!my) return;

    inv = all_inventory(who);
    items = ({});

    weapon     = query_temp("weapon", who);
    sec_weapon = query_temp("secondary_weapon", who);
    handing    = query_temp("handing", who);

    foreach (ob in inv) {
        if (!objectp(ob)) continue;
        if (!who->visible(ob)) continue;

        // Start with full item dbase
        item_dbase = ob->query_entire_dbase();
        item = mapp(item_dbase) ? copy(item_dbase) : ([]);

        // Override/add computed fields
        item["id"]   = query("id", ob) || "unknown";
        item["name"] = ob->name(1) || ob->short() || "???";
        item["base"] = base_name(ob);

        // Equipped status and slot
        if (query("equipped", ob)) {
            slot = (string)who->query_equipping_part(ob);
            item["slot"] = slot;

            if (ob == sec_weapon)
                item["equipped"] = "secondary";
            else
                item["equipped"] = "worn";

            // mod_prop only applies if mod_active (fullsuit set bonus)
            if (query_temp("mod_active", ob))
                item["mod_active"] = 1;
        } else if (ob == handing) {
            item["equipped"] = "holding";
        }

        // Amount for stackable items
        if (function_exists("query_amount", ob) && (int)ob->query_amount() > 1)
            item["amount"] = (int)ob->query_amount();

        // Is it an equipment item?
        if (function_exists("is_equipment", ob) && (int)ob->is_equipment())
            item["is_equipment"] = 1;

        items += ({ item });
    }

    data = ([]);
    data["items"] = items;

    // Encumbrance
    enc     = (int)who->query_encumbrance();
    max_enc = (int)who->query_max_encumbrance();
    if (max_enc > 0)
        data["encumbrance"] = enc * 100 / max_enc;
    else
        data["encumbrance"] = 0;

    // Handing / secondary weapon IDs for GUI marker display
    if (objectp(handing))
        data["handing"] = query("id", handing);
    if (objectp(sec_weapon))
        data["secondary"] = query("id", sec_weapon);

    // Fullsuit bonuses (aggregated from tmp_dbase["fullsuit"])
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

    // Equipment sets (dbase["equipment_set"])
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

// ─── Char.Info ───

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

// ─── Chat.Line ───

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

// ─── Chat.Channels ───

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

// ─── Chat.Channels.Tune ───

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

// ─── Chat.Channels.Send ───

void handle_chat_send(object who, string channel_cmd, string message) {
    if (!who || !stringp(channel_cmd) || !stringp(message)) return;
    if (message == "") return;
    CHANNEL_D->do_channel(who, channel_cmd, message);
}

// ─── Room.Info ───

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

// ─── Equipment Set Handlers (silent, no console output) ───

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

// ─── Handle Incoming GMCP ───

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

// graph_mapd.c
// Graph Map Daemon — topology DB, visibility BFS, GMCP map data
// Created 2026-02-23

#include <room.h>

inherit F_CLEAN_UP;

// ═══ Edge type constants ═══
#define EDGE_STANDARD   0
#define EDGE_DOOR       1
#define EDGE_GATE       2
#define EDGE_FERRY      3
#define EDGE_TRANSPORT  4
#define EDGE_SPECIAL    5
#define EDGE_HIDDEN     6

#define STEP            3    // grid units between adjacent rooms
#define BASE_VIS_RADIUS 3    // BFS depth for visibility

// ═══ Forward declarations ═══
void send_map(object who, string sub_package, mixed data);
void send_map_init(object who);
void send_map_viewstate(object who, string room_id, string room_name,
                        string *vis_add, string *vis_remove, string *explored_add);
void send_map_topology_add(object who, string *room_ids);
void index_room(object room);
void on_room_content_change(object room, object entity, int entering);
void handle_entities_refresh(object who);

// ═══ Global topology DB (nosave — rebuilt from live rooms) ═══
nosave mapping topology_rooms;   // room_id → room data mapping
nosave mapping topology_edges;   // edge_id → edge data mapping
nosave mapping adjacency;        // room_id → ({ edge_id, ... })

// ═══ Entity tracking: room watchers ═══
nosave mapping room_watchers;    // room_id → ({ player_ob, ... })
nosave function room_watch_cb;   // single callback funptr, reused for all rooms

// ═══ Phase 0: Manual coordinates ({ x, y, z, len, wid, hgt }) ═══
// Layout: cross-grid (十) pattern, guangchang at origin.
// Main streets STEP=3 apart. E-W branches offset ±2 in Y to avoid corner overlap.
// All coordinates: x,y = SW corner, l,w,h = room footprint
// Adjacent rooms tile together (share edges).
nosave mapping manual_coords = ([
    // ══════ Central plaza ══════
    "/d/city/guangchang":  ({  0,  0, 0,  3, 3, 1 }),  // 很寬闊廣場

    // ══════ Main E-W street (y=1, 1-unit tall, 3-unit wide segments) ══════
    "/d/city/xidajie1":    ({ -3,  1, 0,  3, 1, 1 }),  // [-3,0]×[1,2]
    "/d/city/xidajie2":    ({ -6,  1, 0,  3, 1, 1 }),  // [-6,-3]×[1,2]
    "/d/city/xidajie3":    ({ -9,  1, 0,  3, 1, 1 }),  // [-9,-6]×[1,2]
    "/d/city/ximen":       ({ -11, 0, 0,  2, 2, 1 }),  // gate
    "/d/city/ximenroad":   ({ -14, 1, 0,  3, 1, 1 }),  // [-14,-11]×[1,2]
    "/d/city/dongdajie1":  ({  3,  1, 0,  3, 1, 1 }),  // [3,6]×[1,2]
    "/d/city/dongdajie2":  ({  6,  1, 0,  3, 1, 1 }),  // [6,9]×[1,2]
    "/d/city/dongdajie3":  ({  9,  1, 0,  3, 1, 1 }),  // [9,12]×[1,2]
    "/d/city/dongmen":     ({  12, 0, 0,  2, 2, 1 }),  // gate

    // ══════ Main N-S street (x=1, 1-unit wide, 3-unit tall segments) ══════
    "/d/city/beidajie1":   ({  1,  3, 0,  1, 3, 1 }),  // [1,2]×[3,6]
    "/d/city/beidajie2":   ({  1,  6, 0,  1, 3, 1 }),  // [1,2]×[6,9]
    "/d/city/beimen":      ({  0,  9, 0,  2, 2, 1 }),  // gate
    "/d/city/nandajie1":   ({  1, -3, 0,  1, 3, 1 }),  // [1,2]×[-3,0]
    "/d/city/nandajie2":   ({  1, -6, 0,  1, 3, 1 }),  // [1,2]×[-6,-3]
    "/d/city/nanmen":      ({  0, -8, 0,  2, 2, 1 }),  // gate

    // ══════ Branches off beidajie1 (east/west) ══════
    "/d/city/kedian":       ({  2,  3, 0,  2, 2, 1 }),  // [2,4]×[3,5] — inn
    "/d/city/qianzhuang":   ({  0,  4, 0,  1, 1, 1 }),  // [0,1]×[4,5] — bank (west of beidajie1)
    "/d/city/majiu":        ({  4,  3, 0,  1, 2, 1 }),  // [4,5]×[3,5] — stable (east of kedian)
    "/d/city/business":     ({  4,  5, 0,  1, 1, 1 }),  // [4,5]×[5,6] — shop (north of majiu)
    "/d/city/hero_shop":    ({  4,  2, 0,  1, 1, 1 }),  // [4,5]×[2,3] — shop (south of majiu)
    "/d/city/shuyuan":      ({  5,  2, 0,  1, 2, 1 }),  // [5,6]×[2,4] — academy (east of majiu, south→dongdajie1)

    // ══════ Branches off beidajie2 (east/west) ══════
    "/d/city/zuixianlou":   ({  2,  6, 0,  2, 2, 1 }),  // [2,4]×[6,8] — famous restaurant
    "/d/city/wumiao":       ({  0,  7, 0,  1, 1, 1 }),  // [0,1]×[7,8] — martial temple

    // ══════ Branches off beimen ══════
    "/d/city/hong-damen":   ({  2,  9, 0,  2, 1, 1 }),  // [2,4]×[9,10] — 氣勢雄偉

    // ══════ Branches off nandajie1 (east/west) ══════
    "/d/city/dangpu":       ({  2, -3, 0,  1, 1, 1 }),  // east of nandajie1
    "/d/city/duchang":      ({ -1, -3, 0,  2, 1, 1 }),  // [-1,1]×[-3,-2] — 豪華宏偉 (west of nandajie1)

    // ══════ Branches off nandajie2 (east/west) ══════
    "/d/city/lichunyuan":   ({  2, -6, 0,  1, 1, 1 }),  // east
    "/d/city/chaguan":      ({  0, -5, 0,  1, 1, 1 }),  // [0,1]×[-5,-4] — west

    // ══════ Branches off nanmen ══════
    "/d/city/jiaowai7":     ({  6, -7, 0,  2, 1, 1 }),  // [6,8]×[-7,-6] — east of nanmen, west of j6
    "/d/city/jiaowai8":     ({ -1, -8, 0,  1, 1, 1 }),  // west of nanmen

    // ══════ North of E-W street (shops/buildings) ══════
    "/d/city/yamen":        ({ -2,  2, 0,  1, 1, 1 }),  // north of xidajie1
    "/d/city/caizhu":       ({ -5,  2, 0,  1, 1, 1 }),  // north of xidajie2
    "/d/city/tianbaoge":    ({ -8,  2, 0,  1, 1, 1 }),  // north of xidajie3
    "/d/city/yaopu":        ({  7,  2, 0,  1, 1, 1 }),  // [7,8]×[2,3] — north of dongdajie2
    "/d/city/huadian":      ({  10, 2, 0,  1, 1, 1 }),  // north of dongdajie3
    "/d/city/ml1":          ({  12, 2, 0,  2, 1, 1 }),  // north of dongmen

    // ══════ South of E-W street ══════
    "/d/city/bingyindamen": ({ -2,  0, 0,  1, 1, 1 }),  // south of xidajie1
    "/d/city/wuguan":       ({ -5,  0, 0,  1, 1, 1 }),  // south of xidajie2
    "/d/city/biaoju":       ({ -8, -1, 0,  2, 2, 1 }),  // [-8,-6]×[-1,1] — 結構宏偉 south of xidajie3
    "/d/city/zahuopu":      ({  3,  0, 0,  1, 1, 1 }),  // south of dongdajie1
    "/d/city/datiepu":      ({  6,  0, 0,  1, 1, 1 }),  // south of dongdajie2
    "/d/city/ma_damen":     ({  9, -1, 0,  2, 2, 1 }),  // [9,11]×[-1,1] — 頗為豪華大宅院
    "/d/city/xiaofang":     ({ -11,-1, 0,  1, 1, 1 }),  // south of ximen
    "/d/city/jiaowai1":     ({  12,-1, 0,  1, 1, 1 }),  // south of dongmen

    // ══════ South gate road ══════
    "/d/city/dujiangqiao":  ({  0,-10, 0,  2, 2, 1 }),  // 三拱石橋 — south of nanmen
    "/d/city/shulin1":      ({ -1,-10, 0,  1, 1, 1 }),  // [-1,0]×[-10,-9] — west of bridge
    "/d/city/matou":        ({  2,-10, 0,  2, 1, 1 }),  // 碼頭 — east of bridge

    // ══════ Government compound (north of yamen) ══════
    "/d/city/ymzhengting":  ({ -3,  3, 0,  2, 2, 1 }),  // [-3,-1]×[3,5] — 衙門正廳
    "/d/city/xiting":       ({ -4,  3, 0,  1, 2, 1 }),  // [-4,-3]×[3,5] — west hall
    "/d/city/dongting":     ({ -1,  3, 0,  1, 2, 1 }),  // [-1,0]×[3,5] — east hall
    "/d/city/neizhai":      ({ -2,  5, 0,  1, 1, 1 }),  // [-2,-1]×[5,6] — inner quarters

    // ══════ Caizhu compound (north of caizhu gate) ══════
    "/d/city/dayuan":       ({ -5,  3, 0,  1, 2, 1 }),  // [-5,-4]×[3,5]
    "/d/city/houyuan":      ({ -5,  5, 0,  1, 2, 1 }),  // [-5,-4]×[5,7]
    "/d/city/xixiang":      ({ -6,  5, 0,  1, 2, 1 }),  // west of houyuan
    "/d/city/dongxiang":    ({ -4,  5, 0,  1, 2, 1 }),  // east of houyuan

    // ══════ Biaoju compound (south of biaoju) ══════
    "/d/city/zhengting":    ({ -7, -3, 0,  1, 2, 1 }),  // [-7,-6]×[-3,-1] — south of biaoju

    // ══════ Bingyin road (south of bingyindamen) ══════
    "/d/city/bingyin":      ({ -2, -2, 0,  1, 2, 1 }),  // [-2,-1]×[-2,0]
    "/d/city/bingqiku":     ({ -2, -4, 0,  1, 2, 1 }),  // [-2,-1]×[-4,-2]

    // ══════ Datiepu area ══════
    "/d/city/wofang":       ({  6, -1, 0,  1, 1, 1 }),  // south of datiepu

    // ══════ Yaopu upper (z=1) ══════
    "/d/city/chanfang":     ({  7,  2, 1,  1, 1, 1 }),  // above yaopu

    // ══════ Lichunyuan upper (z=1) ══════
    "/d/city/lichunyuan2":  ({  2, -6, 1,  1, 1, 1 }),  // above lichunyuan

    // ══════ Zuixianlou upper floors (z=1,2) ══════
    "/d/city/zuixianlou2":  ({  2,  6, 1,  2, 2, 1 }),  // same footprint as ground
    "/d/city/zuixianlou3":  ({  2,  6, 2,  2, 2, 1 }),
    "/d/city/zxlpath":      ({  4,  6, 1,  1, 2, 1 }),  // [4,5]×[6,8] — 大堂
    "/d/city/meigui":       ({  5,  7, 1,  1, 1, 1 }),  // east of zxlpath
    "/d/city/furong":       ({  4,  8, 1,  1, 1, 1 }),  // north of zxlpath
    "/d/city/mudan":        ({  4,  5, 1,  1, 1, 1 }),  // south of zxlpath

    // ══════ Shuyuan upper (z=1) ══════
    "/d/city/shuyuan2":     ({  5,  2, 1,  1, 2, 1 }),  // above shuyuan

    // ══════ Wumiao upper floors (z=1,2) ══════
    "/d/city/wumiao2":      ({  0,  7, 1,  1, 1, 1 }),  // above wumiao
    "/d/city/mingrentang":  ({  0,  7, 2,  1, 1, 1 }),  // above wumiao2

    // ══════ Hong family estate (east of beimen) ══════
    "/d/city/hong-zoulang": ({  4,  9, 0,  2, 1, 1 }),  // [4,6]×[9,10]
    "/d/city/hongniang-zhuang": ({  6, 9, 0, 1, 1, 1 }),
    "/d/city/yinyuan-tang": ({  7,  9, 0,  1, 1, 1 }),

    // ══════ Huadian area ══════
    "/d/city/xiaohuayuan":  ({  10, 3, 0,  1, 1, 1 }),  // north of huadian

    // ══════ Duchang upper (z=1) ══════
    "/d/city/duchang2":     ({ -1, -3, 1,  2, 1, 1 }),  // above duchang

    // ══════ Ma family compound ══════
    "/d/city/ma_dayuan":    ({  9, -3, 0,  2, 2, 1 }),  // [9,11]×[-3,-1]
    "/d/city/ma_chufang":   ({  11,-3, 0,  1, 1, 1 }),  // east of dayuan
    "/d/city/ma_houyuan":   ({  9, -5, 0,  2, 2, 1 }),  // [9,11]×[-5,-3]
    "/d/city/ma_zhengting": ({  9, -8, 0,  2, 2, 1 }),  // [9,11]×[-8,-6] — 非常寬敞明亮
    "/d/city/ma_yantingw":  ({  8, -8, 0,  1, 1, 1 }),  // west of zhengting
    "/d/city/ma_yantinge":  ({  11,-8, 0,  1, 1, 1 }),  // east of zhengting
    "/d/city/ma_zoulang1":  ({  9,-10, 0,  1, 2, 1 }),  // [9,10]×[-10,-8]
    "/d/city/ma_zoulang2":  ({  9,-12, 0,  1, 2, 1 }),  // [9,10]×[-12,-10]
    "/d/city/ma_lianwu1":   ({  9,-15, 0,  2, 2, 1 }),  // [9,11]×[-15,-13] — 空闊場地
    "/d/city/ma_bingqi":    ({  8,-15, 0,  1, 1, 1 }),  // west of lianwu
    "/d/city/ma_xiaojing":  ({  11,-14,0,  1, 1, 1 }),  // east of lianwu
    "/d/city/ma_huayuan":   ({  12,-14,0,  1, 1, 1 }),  // east of xiaojing

    // ══════ Jiaowai road (east side: dongmen south → turns west) ══════
    "/d/city/jiaowai2":     ({  12,-3, 0,  1, 2, 1 }),  // [12,13]×[-3,-1] — south of jiaowai1
    "/d/city/jiaowai3":     ({  12,-5, 0,  1, 2, 1 }),  // [12,13]×[-5,-3]
    "/d/city/jiaowai4":     ({  12,-7, 0,  1, 2, 1 }),  // [12,13]×[-7,-5]
    "/d/city/jiaowai5":     ({  10,-7, 0,  2, 1, 1 }),  // [10,12]×[-7,-6] — west of j4
    "/d/city/jiaowai6":     ({  8, -7, 0,  2, 1, 1 }),  // [8,10]×[-7,-6] — west of j5

    // ══════ Jiaowai road (west side: nanmen west) ══════
    "/d/city/jiaowai9":     ({ -2, -8, 0,  1, 1, 1 }),  // west of j8
    "/d/city/jiaowai10":    ({ -4, -8, 0,  2, 1, 1 }),  // [-4,-2]×[-8,-7]
    "/d/city/jiaowai11":    ({ -6, -8, 0,  2, 1, 1 }),  // [-6,-4]×[-8,-7]
    "/d/city/jiaowai12":    ({ -4, -7, 0,  1, 1, 1 }),  // north of j10
    "/d/city/jiaowai13":    ({ -6, -7, 0,  1, 1, 1 }),  // north of j11

    // ══════ Wudao area (south-west of ximenroad) ══════
    "/d/city/wudao4":       ({ -14, 0, 0,  1, 1, 1 }),  // south of ximenroad
    "/d/city/wudao1":       ({ -16, 0, 0,  2, 1, 1 }),  // [-16,-14]×[0,1] — west of wudao4
    "/d/city/biwu_gate":    ({ -16, 1, 0,  1, 1, 1 }),  // [-16,-15]×[1,2] — north of wudao1
    "/d/city/biwu_road":    ({ -16, 2, 0,  1, 2, 1 }),  // [-16,-15]×[2,4]
    "/d/city/biwu_dating":  ({ -17, 4, 0,  2, 2, 1 }),  // [-17,-15]×[4,6] — 寬敞 巨大擂臺
    "/d/city/biwu_restroom":({ -17, 2, 0,  1, 1, 1 }),  // west of biwu_road
    "/d/city/xinrui_dating":({ -15, 2, 0,  2, 2, 1 }),  // [-15,-13]×[2,4] — 寬敞大房間

    // ══════ Xiyuanmen area (north of ximenroad) ══════
    "/d/city/xym_yzdamen":  ({ -14, 2, 0,  1, 1, 1 }),  // north of ximenroad
    "/d/city/xym_yzfb":     ({ -14, 3, 0,  1, 2, 1 }),  // north of yzdamen

    // ══════ Xiaofang / Didao ══════
    "/d/city/didao":        ({ -12,-1, 0,  1, 1, 1 }),  // underground near xiaofang
]);

void create() {
    seteuid(getuid());
    topology_rooms = ([]);
    topology_edges = ([]);
    adjacency = ([]);
    room_watchers = ([]);
    room_watch_cb = (: on_room_content_change :);
}

// ═══════════════════════════════════════
// Room type classification
// ═══════════════════════════════════════

string classify_room_type(object room) {
    string bn;

    // Check inherits via function_exists as a proxy
    if (function_exists("query_goods_list", room) ||
        function_exists("list_goods", room))
        return "shop";

    if (function_exists("do_deposit", room) ||
        function_exists("do_withdraw", room))
        return "bank";

    if (query("chat_room", room))
        return "chat";

    if (query("valid_startroom", room) ||
        query("restroom", room))
        return "inn";

    if (function_exists("do_cross", room) ||
        function_exists("do_ferry", room))
        return "water";

    bn = base_name(room);
    if (sscanf(bn, "/f/%*s"))
        return "dungeon";

    if (!query("outdoors", room))
        return "indoor";

    return "outdoor";
}

// ═══════════════════════════════════════
// Room flag extraction
// ═══════════════════════════════════════

string *get_room_flags(object room) {
    string *flags;
    flags = ({});
    if (query("no_fight", room))   flags += ({ "safe" });
    if (query("GATE_ROOM", room))  flags += ({ "gate" });
    return flags;
}

// ═══════════════════════════════════════
// NPC flag detection
// ═══════════════════════════════════════

string *get_npc_flags(object npc) {
    string *flags, att;
    flags = ({});

    att = (string)query("attitude", npc);
    if (stringp(att) && (att == "aggressive" || att == "killer"))
        flags += ({ "hostile" });

    if (function_exists("sell_item", npc))
        flags += ({ "vendor" });

    if (function_exists("ask_me", npc))
        flags += ({ "quest" });

    if (function_exists("teach_skill", npc))
        flags += ({ "trainer" });

    return flags;
}

// ═══════════════════════════════════════
// Room entity enumeration
// ═══════════════════════════════════════

// Enumerate all entities in a room. Returns mapping: entity_id → entity_data
mapping get_room_entities(object room) {
    object *inv;
    mapping result, ent_data;
    string eid, label, room_id;
    string *nflags;

    if (!objectp(room)) return ([]);

    result = ([]);
    room_id = base_name(room);
    inv = all_inventory(room);
    if (!arrayp(inv)) return result;

    foreach (object ob in inv) {
        if (userp(ob)) {
            eid = "player:" + (string)query("id", ob);
            label = (string)ob->name(1);
            if (!stringp(label)) label = (string)query("id", ob);
            if (!stringp(label)) label = "player";
            result[eid] = ([
                "id":    eid,
                "type":  "player",
                "room":  room_id,
                "label": label,
            ]);
        } else if (living(ob)) {
            eid = "npc:" + file_name(ob);
            label = (string)ob->short();
            if (!stringp(label)) label = (string)ob->name();
            if (!stringp(label)) label = "NPC";
            nflags = get_npc_flags(ob);
            ent_data = ([
                "id":    eid,
                "type":  "npc",
                "room":  room_id,
                "label": label,
            ]);
            if (sizeof(nflags) > 0) ent_data["flags"] = nflags;
            result[eid] = ent_data;
        } else {
            // Ground item — skip if no short description
            label = (string)ob->short();
            if (!stringp(label) || label == "") continue;
            eid = "item:" + file_name(ob);
            result[eid] = ([
                "id":    eid,
                "type":  "item",
                "room":  room_id,
                "label": label,
            ]);
        }
    }

    return result;
}

// Enumerate entities across all visible rooms
mapping enumerate_visible_entities(string *visible_rooms) {
    mapping all_entities, room_ents;
    object room_ob;

    all_entities = ([]);
    foreach (string rid in visible_rooms) {
        room_ob = find_object(rid);
        if (!room_ob) continue;
        room_ents = get_room_entities(room_ob);
        foreach (string eid, mapping edata in room_ents) {
            all_entities[eid] = edata;
        }
    }
    return all_entities;
}

// ═══════════════════════════════════════
// Entity tracking: build single entity record
// ═══════════════════════════════════════

mapping build_single_entity_record(object ob, string room_id) {
    string eid, label;
    mapping ent_data;
    string *nflags;

    if (userp(ob)) {
        eid = "player:" + (string)query("id", ob);
        label = (string)ob->name(1);
        if (!stringp(label)) label = (string)query("id", ob);
        if (!stringp(label)) label = "player";
        return ([ "id": eid, "type": "player", "room": room_id, "label": label ]);
    } else if (living(ob)) {
        eid = "npc:" + file_name(ob);
        label = (string)ob->short();
        if (!stringp(label)) label = (string)ob->name();
        if (!stringp(label)) label = "NPC";
        ent_data = ([ "id": eid, "type": "npc", "room": room_id, "label": label ]);
        nflags = get_npc_flags(ob);
        if (sizeof(nflags) > 0) ent_data["flags"] = nflags;
        return ent_data;
    } else {
        label = (string)ob->short();
        if (!stringp(label) || label == "") return 0;
        eid = "item:" + file_name(ob);
        return ([ "id": eid, "type": "item", "room": room_id, "label": label ]);
    }
}

// ═══════════════════════════════════════
// Entity tracking: room watch management
// ═══════════════════════════════════════

void register_room_watch(object room) {
    if (!objectp(room)) return;
    watch_object(room, room_watch_cb);
}

void unregister_room_watch(string rid) {
    object room = find_object(rid);
    if (objectp(room))
        unwatch_object(room, room_watch_cb);
}

void update_room_watchers(object player, string *old_visible, string *new_visible) {
    string *removed, *added;

    removed = old_visible - new_visible;
    added   = new_visible - old_visible;

    foreach (string rid in removed) {
        if (room_watchers[rid]) {
            room_watchers[rid] -= ({ player });
            if (!sizeof(room_watchers[rid])) {
                map_delete(room_watchers, rid);
                unregister_room_watch(rid);
            }
        }
    }

    foreach (string rid in added) {
        if (!room_watchers[rid]) {
            room_watchers[rid] = ({});
            register_room_watch(find_object(rid));
        }
        room_watchers[rid] += ({ player });
    }
}

void remove_player_from_watchers(object player) {
    string *visible = player->query_graph_map_visible();
    foreach (string rid in visible) {
        if (room_watchers[rid]) {
            room_watchers[rid] -= ({ player });
            if (!sizeof(room_watchers[rid])) {
                map_delete(room_watchers, rid);
                unregister_room_watch(rid);
            }
        }
    }
}

// ═══════════════════════════════════════
// Entity tracking: driver callback
// ═══════════════════════════════════════

void on_room_content_change(object room, object entity, int entering) {
    string rid, ent_id;
    mapping ent_record;
    object *watchers;

    if (!objectp(room) || !objectp(entity)) return;
    rid = base_name(room);
    watchers = room_watchers[rid];
    if (!arrayp(watchers) || !sizeof(watchers)) return;

    // Build entity record — skip untrackable entities
    ent_record = build_single_entity_record(entity, rid);
    if (!mapp(ent_record)) return;
    ent_id = ent_record["id"];

    foreach (object player in watchers) {
        if (!objectp(player) || !interactive(player)) continue;
        if (player == entity) continue;  // moving player handles own map via on_player_move

        mapping known = player->query_graph_map_known_entities();
        mapping delta;

        if (entering) {
            known[ent_id] = copy(ent_record);
            delta = ([ "add": ({ copy(ent_record) }), "update": ({}), "remove": ({}) ]);
        } else {
            map_delete(known, ent_id);
            delta = ([ "add": ({}), "update": ({}), "remove": ({ ent_id }) ]);
        }

        player->set_graph_map_known_entities(known);
        send_map(player, "EntitiesDelta", delta);
    }
}

// ═══════════════════════════════════════
// Room indexing
// ═══════════════════════════════════════

void index_room(object room) {
    string room_id, zone, room_type;
    mapping exits, doors_data;
    string *flags;
    int x, y, z, len, wid, hgt;
    mixed mc;

    if (!objectp(room)) return;

    room_id = base_name(room);
    if (topology_rooms[room_id]) return;  // already indexed

    // Coordinates: check manual table first, then room data
    mc = manual_coords[room_id];
    if (mc) {
        x   = mc[0]; y   = mc[1]; z   = mc[2];
        len = mc[3]; wid = mc[4]; hgt = mc[5];
    } else {
        x   = (int)query("coor/x", room);
        y   = (int)query("coor/y", room);
        z   = (int)query("coor/z", room);
        len = (int)query("coor/length", room) || 1;
        wid = (int)query("coor/width", room)  || 1;
        hgt = (int)query("coor/height", room) || 1;
    }

    zone = query("outdoors", room);
    if (!stringp(zone)) zone = "";
    room_type = classify_room_type(room);
    flags = get_room_flags(room);

    topology_rooms[room_id] = ([
        "name":      room->short() || "未知",
        "zone":      zone,
        "room_type": room_type,
        "x": x, "y": y, "z": z,
        "len": len, "wid": wid, "hgt": hgt,
        "flags": flags,
        "positioned": (mc || x != 0 || y != 0 || z != 0) ? 1 : 0,
    ]);

    // Index exits as edges
    exits = query("exits", room);
    doors_data = room->query_doors();
    if (!mapp(doors_data)) doors_data = ([]);

    if (mapp(exits)) {
        foreach (string dir, string dest in exits) {
            string edge_id = room_id + "|" + dir + "|" + dest;
            int edge_type = EDGE_STANDARD;
            if (doors_data[dir]) edge_type = EDGE_DOOR;

            topology_edges[edge_id] = ([
                "from": room_id,
                "to":   dest,
                "cmd":  dir,
                "type": edge_type,
            ]);

            if (!adjacency[room_id]) adjacency[room_id] = ({});
            adjacency[room_id] += ({ edge_id });
        }
    }
}

// ═══════════════════════════════════════
// Visibility BFS engine
// ═══════════════════════════════════════

string *compute_visible(string start_room) {
    string *visible, *frontier, *next_frontier, *room_edges;
    mapping visited, edge;
    string neighbor;
    object room_ob;
    int depth;

    visible = ({ start_room });
    visited = ([ start_room: 1 ]);
    frontier = ({ start_room });
    depth = 0;

    while (depth < BASE_VIS_RADIUS && sizeof(frontier) > 0) {
        next_frontier = ({});
        foreach (string room_id in frontier) {
            room_edges = adjacency[room_id];
            if (!arrayp(room_edges)) continue;

            foreach (string edge_id in room_edges) {
                edge = topology_edges[edge_id];
                if (!edge) continue;
                neighbor = edge["to"];
                if (visited[neighbor]) continue;

                // Index neighbor room if not yet indexed
                if (!topology_rooms[neighbor]) {
                    room_ob = find_object(neighbor);
                    if (!room_ob) {
                        catch(room_ob = load_object(neighbor));
                    }
                    if (room_ob) {
                        index_room(room_ob);
                    }
                }

                if (!topology_rooms[neighbor]) continue;

                visited[neighbor] = 1;
                visible += ({ neighbor });
                next_frontier += ({ neighbor });
            }
        }
        frontier = next_frontier;
        depth++;
    }

    return visible;
}

// ═══════════════════════════════════════
// GMCP send helpers
// ═══════════════════════════════════════

void send_map(object who, string sub_package, mixed data) {
    object gd;
    gd = find_object(GMCP_D);
    if (!gd) gd = load_object(GMCP_D);
    if (!gd) return;
    gd->gmcp_send(who, "Map." + sub_package, data);
}

// Build room data array for GMCP transport (skip unpositioned rooms)
mixed *build_room_array(string *room_ids) {
    mixed *rooms;
    rooms = ({});
    foreach (string rid in room_ids) {
        mapping rd;
        rd = topology_rooms[rid];
        if (!rd) continue;
        if (!rd["positioned"]) continue;  // skip rooms without coordinates
        rooms += ({ ([
            "id":        rid,
            "name":      rd["name"],
            "zone":      rd["zone"],
            "x":         rd["x"],
            "y":         rd["y"],
            "z":         rd["z"],
            "len":       rd["len"],
            "wid":       rd["wid"],
            "hgt":       rd["hgt"],
            "room_type": rd["room_type"],
            "flags":     rd["flags"],
        ]) });
    }
    return rooms;
}

// Build edge data array — only edges connecting positioned rooms in the set
mixed *build_edge_array(string *room_ids) {
    mixed *edges;
    mapping seen, room_set, rd_from, rd_to;
    edges = ({});
    seen = ([]);
    room_set = ([]);
    foreach (string rid in room_ids) room_set[rid] = 1;

    foreach (string rid in room_ids) {
        string *edge_ids;
        rd_from = topology_rooms[rid];
        if (!rd_from || !rd_from["positioned"]) continue;  // skip unpositioned source
        edge_ids = adjacency[rid];
        if (!arrayp(edge_ids)) continue;
        foreach (string eid in edge_ids) {
            mapping ed;
            if (seen[eid]) continue;
            seen[eid] = 1;
            ed = topology_edges[eid];
            if (!ed) continue;
            // Include if destination is also in the set AND positioned
            if (room_set[ed["to"]]) {
                rd_to = topology_rooms[ed["to"]];
                if (!rd_to || !rd_to["positioned"]) continue;
                edges += ({ ([
                    "id":   eid,
                    "from": ed["from"],
                    "to":   ed["to"],
                    "cmd":  ed["cmd"],
                    "type": ed["type"],
                ]) });
            }
        }
    }
    return edges;
}

// ═══════════════════════════════════════
// Entity delta computation
// ═══════════════════════════════════════

// Compute add/update/remove delta between entity snapshots.
// old_snap: entity_id → entity_data (last known state)
// new_snap: entity_id → entity_data (current state)
mapping compute_entity_delta(mapping old_snap, mapping new_snap) {
    mixed *add_list, *update_list, *remove_list;
    mapping ndata, odata;

    add_list    = ({});
    update_list = ({});
    remove_list = ({});

    foreach (string eid, ndata in new_snap) {
        odata = old_snap[eid];
        if (!odata) {
            add_list += ({ ndata });
        } else if (ndata["room"] != odata["room"] ||
                   ndata["label"] != odata["label"]) {
            // Room changed, or label/description changed
            update_list += ({ ndata });
        }
    }

    foreach (string eid in keys(old_snap)) {
        if (!new_snap[eid])
            remove_list += ({ eid });
    }

    return ([
        "add":    add_list,
        "update": update_list,
        "remove": remove_list,
    ]);
}

void send_entities_delta(object who, mapping old_snap, mapping new_snap) {
    mapping delta;
    delta = compute_entity_delta(old_snap, new_snap);

    if (sizeof(delta["add"]) > 0 || sizeof(delta["update"]) > 0 ||
        sizeof(delta["remove"]) > 0) {
        send_map(who, "EntitiesDelta", delta);
    }
}

// ═══════════════════════════════════════
// POI builder (static from room properties)
// NOTE: POIs are sent inline with Map.Init and Map.TopologyAdd.
//       Map.POIDelta is reserved for future dynamic POIs (quest markers, events).
// ═══════════════════════════════════════

mixed *build_poi_array(string *room_ids) {
    mixed *pois;
    mapping rd, trans_data;
    string room_type, cat;

    pois = ({});

    // Build transport hub set from MAP_D
    mapping trans_rooms;
    trans_rooms = ([]);
    trans_data = (mapping)MAP_D->query_trans_info();
    if (mapp(trans_data)) {
        foreach (string zone, mixed tdata in trans_data) {
            if (mapp(tdata) && stringp(tdata["room"]))
                trans_rooms[tdata["room"]] = 1;
        }
    }

    foreach (string rid in room_ids) {
        rd = topology_rooms[rid];
        if (!rd) continue;

        room_type = rd["room_type"];
        cat = "";

        if (room_type == "shop")       cat = "shop";
        else if (room_type == "bank")  cat = "bank";
        else if (room_type == "inn")   cat = "inn";
        else if (room_type == "water") cat = "transport";

        if (trans_rooms[rid]) cat = "transport";

        if (cat == "") continue;

        pois += ({ ([
            "id":       "poi:" + cat + ":" + rid,
            "room":     rid,
            "category": cat,
            "label":    rd["name"] || rid,
        ]) });
    }

    return pois;
}

// ═══════════════════════════════════════
// Map.Hello handler
// ═══════════════════════════════════════

void handle_hello(object who, mapping params) {
    if (!who || !interactive(who)) return;

    who->set_graph_map_subscribed(1);

    // Send Map.Init
    send_map_init(who);
}

// Map.EntitiesRefresh handler — client requests full entity resync
void handle_entities_refresh(object who) {
    mapping old_entities, new_entities;
    string *visible;

    if (!who || !interactive(who)) return;
    if (!who->has_graph_map()) return;

    visible = who->query_graph_map_visible();
    if (!arrayp(visible) || !sizeof(visible)) return;

    old_entities = who->query_graph_map_known_entities();
    new_entities = enumerate_visible_entities(visible);
    who->set_graph_map_known_entities(new_entities);
    send_entities_delta(who, old_entities, new_entities);
}

// Called when a player disconnects or map subscription ends
void handle_goodbye(object who) {
    if (!who) return;
    remove_player_from_watchers(who);
    who->set_graph_map_subscribed(0);
    who->set_graph_map_visible(({ }));
    who->set_graph_map_known_entities(([  ]));
}

// ═══════════════════════════════════════
// Map.Init — full state push
// ═══════════════════════════════════════

void send_map_init(object who) {
    object env;
    string current_id;
    string *visible;
    mapping explored, initial_entities;
    mixed *rooms, *edges, *entities_array, *pois_array;

    env = environment(who);
    if (!env) return;

    current_id = base_name(env);
    index_room(env);

    // Compute initial visibility
    visible = compute_visible(current_id);
    update_room_watchers(who, ({}), visible);
    who->set_graph_map_visible(visible);

    // Mark all visible as explored
    foreach (string rid in visible) {
        who->mark_explored(rid);
    }

    explored = who->query_graph_map_explored();

    // Build topology for visible neighborhood (immediate render)
    rooms = build_room_array(visible);
    edges = build_edge_array(visible);

    // Enumerate entities for visible rooms
    initial_entities = enumerate_visible_entities(visible);
    who->set_graph_map_known_entities(initial_entities);
    entities_array = values(initial_entities);

    // Build POI array for visible rooms
    pois_array = build_poi_array(visible);

    send_map(who, "Init", ([
        "ver": 1,
        "config": ([
            "base_vis_radius": BASE_VIS_RADIUS,
        ]),
        "character": ([
            "room_id":        current_id,
            "room_name":      env->short() || "未知",
            "entity_id":      "player:" + (string)query("id", who),
            "explored_count": sizeof(explored),
        ]),
        "topology": ([
            "rooms": rooms,
            "edges": edges,
        ]),
        "visible": visible,
        "entities": entities_array,
        "pois":     pois_array,
    ]));

    // Stream remaining explored rooms in batches
    {
        string *remaining;
        remaining = keys(explored) - visible;
        if (sizeof(remaining) > 0)
            call_out("stream_explored_topology", 0, who, remaining, 0);
    }
}

// Stream explored topology in batches of 50
void stream_explored_topology(object who, string *remaining, int offset) {
    int batch_size, end_idx;
    string *batch;
    mixed *rooms, *edges, *pois;

    if (!who || !interactive(who)) return;
    if (!who->has_graph_map()) return;

    batch_size = 50;
    end_idx = offset + batch_size;
    if (end_idx > sizeof(remaining)) end_idx = sizeof(remaining);

    batch = remaining[offset..end_idx-1];
    rooms = build_room_array(batch);
    edges = build_edge_array(batch);
    pois  = build_poi_array(batch);

    if (sizeof(rooms) > 0) {
        send_map(who, "TopologyAdd", ([
            "rooms": rooms,
            "edges": edges,
            "pois":  pois,
        ]));
    }

    if (end_idx < sizeof(remaining))
        call_out("stream_explored_topology", 0, who, remaining, end_idx);
}

// ═══════════════════════════════════════
// Map.ViewState — sent on every move
// ═══════════════════════════════════════

void send_map_viewstate(object who, string room_id, string room_name,
                        string *vis_add, string *vis_remove, string *explored_add) {
    send_map(who, "ViewState", ([
        "room":           room_id,
        "room_name":      room_name,
        "visible_add":    vis_add,
        "visible_remove": vis_remove,
        "explored_add":   explored_add,
    ]));
}

// ═══════════════════════════════════════
// Map.TopologyAdd — send newly explored rooms
// ═══════════════════════════════════════

void send_map_topology_add(object who, string *room_ids) {
    mixed *rooms, *edges, *pois;
    rooms = build_room_array(room_ids);
    edges = build_edge_array(room_ids);
    pois  = build_poi_array(room_ids);

    send_map(who, "TopologyAdd", ([
        "rooms": rooms,
        "edges": edges,
        "pois":  pois,
    ]));
}

// ═══════════════════════════════════════
// Player movement handler (called from go.c)
// ═══════════════════════════════════════

void on_player_move(object player, object old_room, object new_room, string dir) {
    string old_id, new_id, edge_id;
    string *old_visible, *new_visible, *vis_add, *vis_remove;
    string *explored_add;
    mapping explored;

    if (!player || !old_room || !new_room) return;
    if (!player->has_graph_map()) return;

    old_id = base_name(old_room);
    new_id = base_name(new_room);

    // Index both rooms
    index_room(old_room);
    index_room(new_room);

    // Record edge (may be new)
    edge_id = old_id + "|" + dir + "|" + new_id;
    if (!topology_edges[edge_id]) {
        topology_edges[edge_id] = ([
            "from": old_id,
            "to":   new_id,
            "cmd":  dir,
            "type": EDGE_STANDARD,
        ]);
        if (!adjacency[old_id]) adjacency[old_id] = ({});
        adjacency[old_id] += ({ edge_id });
    }

    // Compute visibility delta
    old_visible = player->query_graph_map_visible();
    new_visible = compute_visible(new_id);

    vis_add = new_visible - old_visible;
    vis_remove = old_visible - new_visible;

    // Check newly explored rooms
    explored = player->query_graph_map_explored();
    explored_add = ({});
    foreach (string rid in new_visible) {
        if (!explored[rid]) {
            player->mark_explored(rid);
            explored_add += ({ rid });
        }
    }

    // Update room watchers before changing visible set
    update_room_watchers(player, old_visible, new_visible);
    player->set_graph_map_visible(new_visible);

    // Push GMCP updates
    send_map_viewstate(player, new_id,
        new_room->short() || "未知",
        vis_add, vis_remove, explored_add);

    // Send topology for newly explored rooms
    if (sizeof(explored_add)) {
        send_map_topology_add(player, explored_add);
    }

    // Entity delta: enumerate current entities, diff with previous snapshot
    {
        mapping old_entities, new_entities;
        old_entities = player->query_graph_map_known_entities();
        new_entities = enumerate_visible_entities(new_visible);
        player->set_graph_map_known_entities(new_entities);
        send_entities_delta(player, old_entities, new_entities);
    }
}

// Special/non-standard movement (from move.c hook)
void on_raw_move(object player, object old_room, object new_room, string move_type) {
    on_player_move(player, old_room, new_room, move_type);
}

// ═══════════════════════════════════════
// Player login handler
// ═══════════════════════════════════════

void on_player_login(object who) {
    object env;
    if (!who || !interactive(who)) return;

    env = environment(who);
    if (!env || !env->is_room()) return;

    // Pre-index current room so Map.Hello response is fast
    index_room(env);
}

// ═══════════════════════════════════════
// Query API (for admin/debug)
// ═══════════════════════════════════════

mapping query_room_data(string room_id) {
    return topology_rooms[room_id];
}

mapping query_topology_rooms() { return topology_rooms; }
mapping query_topology_edges() { return topology_edges; }
int query_indexed_count() { return sizeof(topology_rooms); }

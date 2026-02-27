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
    "/d/city/xym_yzdamen":  ({ -13, 2, 0,  1, 1, 1 }),  // [-13,-12]×[2,3] north of ximenroad
    "/d/city/xym_yzfb":     ({ -13, 3, 0,  1, 2, 1 }),  // [-13,-12]×[3,5] north of yzdamen

    // ══════ Xiaofang / Didao ══════
    "/d/city/didao":        ({ -12,-1, 0,  1, 1, 1 }),  // underground near xiaofang

    // ══════ Biwu leitai (z=1 above biwu_dating) ══════
    "/d/city/biwu_leitai":  ({ -17, 4, 1,  2, 2, 1 }),  // z=1 擂臺 — jump from biwu_dating

    // ══════ Kedian extensions (z=0) ══════
    "/d/city/stock":        ({  2,  5, 0,  1, 1, 1 }),  // [2,3]×[5,6] — 證券交易所 north of kedian
    "/d/city/liaotian":     ({  3,  5, 0,  1, 1, 1 }),  // [3,4]×[5,6] — 客店茶房 north of kedian

    // ══════ Kedian upper floors (z=1) ══════
    "/d/city/kedian2":      ({  2,  3, 1,  2, 2, 1 }),  // [2,4]×[3,5] z=1 — 客店二樓
    "/d/city/kedian3":      ({  4,  3, 1,  1, 1, 1 }),  // [4,5]×[3,4] z=1 — 客店二樓 (inner room)

    // ══════ Kedian basement (z=-1) ══════
    "/d/city/kedian5":      ({  2,  3,-1,  1, 1, 1 }),  // [2,3]×[3,4] z=-1 — 天龍殿
    "/d/city/zhujuan":      ({  3,  3,-1,  1, 1, 1 }),  // [3,4]×[3,4] z=-1 — 豬圈

    // ══════ PM auction corridor (z=-1, north from kedian basement) ══════
    "/d/city/pmc":          ({  4,  3,-1,  1, 1, 1 }),  // [4,5]×[3,4] — 拍賣場 entrance
    "/d/city/pm_road1":     ({  4,  4,-1,  1, 1, 1 }),  // 金色走廊
    "/d/city/pm_road2":     ({  4,  5,-1,  1, 1, 1 }),
    "/d/city/pm_road3":     ({  4,  6,-1,  1, 1, 1 }),
    "/d/city/pm_road4":     ({  4,  7,-1,  1, 1, 1 }),
    "/d/city/pm_road5":     ({  4,  8,-1,  1, 1, 1 }),
    "/d/city/pm_road6":     ({  4,  9,-1,  1, 1, 1 }),
    "/d/city/pm_road7":     ({  4, 10,-1,  1, 1, 1 }),
    "/d/city/pm_road8":     ({  4, 11,-1,  1, 1, 1 }),
    "/d/city/pm_restroom":  ({  4, 12,-1,  1, 1, 1 }),  // 休息室 end of corridor

    // ══════ Tree / hidden area above guangchang ══════
    "/d/city/tree":         ({  1,  1, 1,  1, 1, 1 }),  // z=1 大榕樹上
    "/d/city/tree2":        ({  1,  1, 2,  1, 1, 1 }),  // z=2 大榕樹上 (higher)
    "/d/city/kedian4":      ({  1,  1, 3,  1, 1, 1 }),  // z=3 大隱閣 (treetop)
    "/d/city/swing":        ({  1,  0, 3,  1, 1, 1 }),  // z=3 鞦韆園 south of kedian4
    "/d/city/tzc":          ({  2,  0, 1,  1, 1, 1 }),  // z=1 挑戰擂臺 above guangchang

    // ══════ Chashi / Garments upper floors (z=1) ══════
    "/d/city/chashi":       ({  0, -5, 1,  1, 1, 1 }),  // z=1 茶室 above chaguan
    "/d/city/garments":     ({  3,  0, 1,  1, 1, 1 }),  // z=1 成衣店 above zahuopu

    // ══════ Wudao extensions + Leitai ══════
    "/d/city/wudao2":       ({ -13, 0, 0,  1, 1, 1 }),  // 武道場 east of wudao4
    "/d/city/wudao3":       ({ -14,-1, 0,  1, 1, 1 }),  // 武道場 south of wudao4
    "/d/city/mishuchu":     ({ -16,-1, 0,  1, 1, 1 }),  // 報名處 south of wudao1
    "/d/city/leitai":       ({ -16, 0, 1,  2, 1, 1 }),  // z=1 擂臺 above wudao1
    "/d/city/leitai2":      ({ -13, 0, 1,  1, 1, 1 }),  // z=1 擂臺 above wudao2
    "/d/city/leitai3":      ({ -14,-1, 1,  1, 1, 1 }),  // z=1 擂臺 above wudao3
    "/d/city/yws":          ({ -14, 0, 1,  1, 1, 1 }),  // z=1 醫務室 east of leitai

    // ══════ Ymzhengting upper floor (z=1) ══════
    "/d/city/ymzhengting1": ({ -3,  3, 1,  2, 2, 1 }),  // z=1 衙門正廳 above ymzhengting

    // ══════ Daxiao / Bocai gambling annex ══════
    "/d/city/daxiao":       ({ -3, -3, 0,  1, 1, 1 }),  // 賭場 west of duchang
    "/d/city/bocai":        ({ -3, -2, 0,  1, 1, 1 }),  // 博彩 north of daxiao

    // ══════ Duchang2 pig game rooms (z=1) ══════
    "/d/city/eproom":       ({  1, -3, 1,  1, 1, 1 }),  // 拱豬房 east of duchang2
    "/d/city/nproom":       ({  0, -2, 1,  1, 1, 1 }),  // 拱豬房 north of duchang2
    "/d/city/sproom":       ({  0, -4, 1,  1, 1, 1 }),  // 拱豬房 south of duchang2
    "/d/city/wproom":       ({ -2, -3, 1,  1, 1, 1 }),  // 拱豬房 west of duchang2

    // ══════ Bamboo grove 青竹林 (east of dongmen) ══════
    "/d/city/ml2":          ({  14, 2, 0,  1, 1, 1 }),  // east of ml1
    "/d/city/ml3":          ({  14, 3, 0,  1, 1, 1 }),  // north of ml2
    "/d/city/ml4":          ({  13, 3, 0,  1, 1, 1 }),  // west of ml3
    "/d/city/ml5":          ({  13, 4, 0,  1, 1, 1 }),  // north of ml4
    "/d/city/ml6":          ({  14, 4, 0,  1, 1, 1 }),  // east of ml5
    "/d/city/ml7":          ({  14, 5, 0,  1, 1, 1 }),  // north of ml6
    "/d/city/pomiao":       ({  15, 5, 0,  1, 1, 1 }),  // 土地廟 east of ml7
    "/d/city/gbandao":      ({  15, 6, 0,  1, 1, 1 }),  // 暗道 north of pomiao (behind door)
    "/d/city/gbxiaowu":     ({  16, 6, 0,  1, 1, 1 }),  // 林間小屋 east of gbandao

    // ══════ Shulin maze / Xiaodao HQ ══════
    "/d/city/shulin":       ({ -2,-10, 0,  1, 1, 1 }),  // 樹林 maze west of shulin1
    "/d/city/xdhzb":        ({ -3,-10, 0,  1, 1, 1 }),  // 小刀會總部 west of shulin

    // ╔═══════════════════════════════════════════════════════════╗
    // ║  WUDANG (武當山) — 118 rooms, 4 z-levels                 ║
    // ║  z=0: approach road + foothills + mountain ascent        ║
    // ║  z=1: Zixiao Palace + peach garden + south cliff         ║
    // ║  z=2: summit path (three gates → golden summit)          ║
    // ║  z=-1: nanyan underground maze                           ║
    // ╚═══════════════════════════════════════════════════════════╝

    // ══════ Wudang z=0: Approach road from city ══════
    "/d/wudang/wdroad1":    ({  0,-12, 0,  1, 1, 1 }),  // 青石大道 — n→city/dujiangqiao
    "/d/wudang/wdroad2":    ({  0,-13, 0,  1, 1, 1 }),  // 青石大道 — w→hudie, se→yixing
    "/d/wudang/wdroad3":    ({  0,-14, 0,  1, 1, 1 }),  // 青石大道
    "/d/wudang/wdroad4":    ({  0,-15, 0,  1, 1, 1 }),  // 青石大道 — e→xiaoyao, sw→henshan
    "/d/wudang/wdroad5":    ({ -1,-15, 0,  1, 1, 1 }),  // 青石大道 — n→xiangyang, sd→jingzhou

    // ══════ Wudang z=0: Foothills ══════
    "/d/wudang/wdroad6":    ({ -2,-14, 0,  1, 1, 1 }),  // 小路 — nw of wdroad5
    "/d/wudang/house":      ({ -2,-15, 0,  1, 1, 1 }),  // 小土屋 — s of wdroad6
    "/d/wudang/wdroad7":    ({ -3,-14, 0,  1, 1, 1 }),  // 小路 — w of wdroad6
    "/d/wudang/wdroad8":    ({ -4,-15, 0,  1, 1, 1 }),  // 小路 — sw of wdroad7
    "/d/wudang/sanbuguan":  ({ -5,-15, 0,  1, 1, 1 }),  // 三不管 — sw→emei, n→yuanyue
    "/d/wudang/wdroad9":    ({ -4,-16, 0,  1, 1, 1 }),  // 黃土路 — se of sanbuguan
    "/d/wudang/wdroad10":   ({ -4,-17, 0,  1, 1, 1 }),  // 黃土路

    // ══════ Wudang z=0: Songlin area ══════
    "/d/wudang/slxl1":      ({ -5,-17, 0,  1, 1, 1 }),  // 松林小路 — w of wdroad10
    "/d/wudang/slxl2":      ({ -6,-17, 0,  1, 1, 1 }),  // 松林小路 — w of slxl1
    "/d/wudang/songlin1":   ({ -6,-18, 0,  1, 1, 1 }),  // 松林 — s of slxl2
    "/d/wudang/songlin2":   ({ -6,-16, 0,  1, 1, 1 }),  // 松林 — n of slxl2
    "/d/wudang/songlin3":   ({ -6,-19, 0,  1, 1, 1 }),  // 松林 — s of songlin1
    "/d/wudang/songlin4":   ({ -6,-15, 0,  1, 1, 1 }),  // 松林 — n of songlin2

    // ══════ Wudang z=0: Tufeiwo bandit area ══════
    "/d/wudang/tufeiwo1":   ({ -4,-18,  1,  1, 1, 1 }),  // 林中小路 — s of wdroad10
    "/d/wudang/tufeiwo2":   ({ -4,-19,  1,  1, 1, 1 }),  // 林中小路
    "/d/wudang/tufeiwo3":   ({ -3,-19,  1,  1, 1, 1 }),  // 林中小路 — e of tufeiwo2

    // ══════ Wudang z=0: Gate area ══════
    "/d/wudang/jiejianyan": ({ -7,-17,  1,  1, 1, 1 }),  // 解劍巖
    "/d/wudang/slxl3":      ({ -8,-17,  2,  1, 1, 1 }),  // 松林小路
    "/d/wudang/xuanyuegate":({ -9,-17,  2,  1, 1, 1 }),  // 玄嶽門

    // ══════ Wudang z=0: Pine forest (random maze) ══════
    "/d/wudang/pine_road":  ({ -9,-14,  2,  1, 1, 1 }),  // 松林大道
    "/d/wudang/pine_road1": ({ -9,-13,  2,  1, 1, 1 }),  // 松林小路 — n of pine_road
    "/d/wudang/pine_road2": ({ -9,-15,  2,  1, 1, 1 }),  // 松林小路 — s of pine_road
    "/d/wudang/pine_forest0": ({ -9,-12, 2, 1, 1, 1 }),  // 松林 maze entry
    "/d/wudang/pine_forest1": ({ -9,-16, 2, 1, 1, 1 }),  // 松林 maze entry
    "/d/wudang/pine_forest2": ({-10,-12, 2, 1, 1, 1 }),  // 松林 random maze
    "/d/wudang/pine_forest3": ({-10,-13, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest4": ({-10,-14, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest5": ({-10,-15, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest6": ({-10,-16, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest7": ({-11,-13, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest8": ({-11,-14, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest9": ({-11,-15, 2, 1, 1, 1 }),  // 松林
    "/d/wudang/pine_forest10":({-11,-16, 2, 1, 1, 1 }),  // 松中草地

    // ══════ Wudang z=0: Mountain ascent ══════
    "/d/wudang/shijie1":    ({ -9,-18,  3,  1, 1, 1 }),  // 石階 — s of xuanyuegate
    "/d/wudang/yuzhengong": ({ -9,-19,  4,  1, 1, 1 }),  // 遇真宮
    "/d/wudang/wdbl":       ({ -9,-20,  5,  1, 1, 1 }),  // 武當柏林
    "/d/wudang/wdbl1":      ({-10,-20,  5,  1, 1, 1 }),  // 柏林 — w of wdbl
    "/d/wudang/wdbl2":      ({ -8,-20,  5,  1, 1, 1 }),  // 柏林 — e of wdbl
    "/d/wudang/haohanpo":   ({ -9,-21,  6,  1, 1, 1 }),  // 好漢坡
    "/d/wudang/shanlu1":    ({ -9,-22,  5,  1, 1, 1 }),  // 山路
    "/d/wudang/mozhenjing": ({ -8,-22,  5,  1, 1, 1 }),  // 磨針井 — e of shanlu1
    "/d/wudang/taizipo":    ({ -9,-23,  6,  1, 1, 1 }),  // 太子坡
    "/d/wudang/fuzhenguan": ({ -8,-23,  6,  1, 1, 1 }),  // 復真觀五層樓 — e of taizipo
    "/d/wudang/shiliang":   ({ -9,-24,  5,  1, 1, 1 }),  // 石樑
    "/d/wudang/shop":       ({ -8,-24,  5,  1, 1, 1 }),  // 小吃店 — e of shiliang
    "/d/wudang/shibapan":   ({ -9,-25,  6,  1, 1, 1 }),  // 十八盤
    "/d/wudang/shijie2":    ({ -9,-26,  7,  1, 1, 1 }),  // 石階
    "/d/wudang/zixiaogate": ({ -9,-27,  8,  1, 1, 1 }),  // 紫霄宮大門

    // ══════ Wudang z=1: Zixiao Palace — main complex ══════
    "/d/wudang/guangchang": ({ -9,-28,  9,  1, 2, 1 }),  // 武當廣場 (1×2)
    "/d/wudang/sanqingdian":({ -9,-29,  9,  1, 1, 1 }),  // 三清殿 — s of guangchang
    "/d/wudang/houyuan":    ({ -9,-30,  9,  1, 1, 1 }),  // 後院 — s of sanqingdian
    "/d/wudang/xiaolu1":    ({ -9,-31,  9,  1, 1, 1 }),  // 林間小徑
    "/d/wudang/xiaolu2":    ({ -9,-32,  9,  1, 1, 1 }),  // 林間小徑 (竹門 door)
    "/d/wudang/xiaoyuan":   ({ -9,-33,  9,  1, 1, 1 }),  // 後山小院 (竹門 door)

    // ══════ Wudang z=1: West wing (xilang → caolianfang) ══════
    "/d/wudang/xilang":     ({-10,-29,  9,  1, 1, 1 }),  // 西廂走廊 — w of sanqingdian
    "/d/wudang/cangjingge": ({-10,-28, 10,  1, 1, 1 }),  // 藏經閣 — n of xilang
    "/d/wudang/caolianfang":({-11,-29, 10,  1, 1, 1 }),  // 操練房 — w of xilang
    "/d/wudang/caolian1":   ({-11,-30, 10,  1, 1, 1 }),  // 南間操練房 — s
    "/d/wudang/caolian2":   ({-11,-28, 10,  1, 1, 1 }),  // 北間操練房 — n
    "/d/wudang/caolian3":   ({-12,-29, 10,  1, 1, 1 }),  // 西間操練房 — w

    // ══════ Wudang z=1: East wing (donglang corridor) ══════
    "/d/wudang/donglang1":  ({ -8,-29,  9,  1, 1, 1 }),  // 東廂走廊 — e of sanqingdian
    "/d/wudang/donglang2":  ({ -7,-29,  9,  1, 1, 1 }),  // 東廂走廊 — e of donglang1
    "/d/wudang/xiuxishi":   ({ -7,-28,  9,  1, 1, 1 }),  // 休息室 — n of donglang2
    "/d/wudang/chashi":     ({ -7,-30,  9,  1, 1, 1 }),  // 茶室 — s of donglang2
    "/d/wudang/liangongfang":({-6,-29,  9,  1, 1, 1 }),  // 練功房 — e of donglang2

    // ══════ Wudang z=1: Shanlu path (guangchang east) ══════
    "/d/wudang/shanlu2":    ({ -8,-27,  9,  1, 1, 1 }),  // 山路 — e of guangchang
    "/d/wudang/shanlu3":    ({ -7,-27,  9,  1, 1, 1 }),  // 山路 — e of shanlu2
    "/d/wudang/shanlu4":    ({ -7,-28, 10,  1, 1, 1 }),  // 山路 — s of shanlu3

    // ══════ Wudang z=1: South cliff area ══════
    "/d/wudang/taiziyan":   ({ -3,-28, 11,  1, 1, 1 }),  // 太子巖 — su from shanlu4
    "/d/wudang/langmeiyuan":({ -3,-29, 10,  1, 1, 1 }),  // 榔梅園 — sd from taiziyan
    "/d/wudang/nanyanfeng": ({ -4,-29, 11,  1, 1, 1 }),  // 南巖峰 — wu from langmeiyuan
    "/d/wudang/sheshenya":  ({ -5,-29, 11,  1, 1, 1 }),  // 捨身崖 — w of nanyanfeng
    "/d/wudang/shizhu":     ({ -4,-30, 10,  1, 1, 1 }),  // 石柱 — sd from nanyanfeng
    "/d/wudang/nanyangong": ({ -3,-30, 10,  1, 1, 1 }),  // 南巖宮 — enter from shizhu
    "/d/wudang/gaotai":     ({ -3,-31, 11,  1, 1, 1 }),  // 南巖宮高臺 — su from nanyangong

    // ══════ Wudang z=1: Peach garden (tyroad1-13 + branches) ══════
    "/d/wudang/tyroad1":    ({ -8,-31,  8,  1, 1, 1 }),  // 石階 — edown from guangchang
    "/d/wudang/tyroad2":    ({ -7,-31,  8,  1, 1, 1 }),  // 石階 — e
    "/d/wudang/tyroad3":    ({ -6,-31,  8,  1, 1, 1 }),  // 石階 — e
    "/d/wudang/tyroad4":    ({ -5,-31,  7,  1, 1, 1 }),  // 崎嶇山路 — e
    "/d/wudang/tyroad5":    ({ -5,-32,  6,  1, 1, 1 }),  // 崎嶇山路 — s
    "/d/wudang/tyroad6":    ({ -4,-32,  5,  1, 1, 1 }),  // 崎嶇山路 — e
    "/d/wudang/tyroad7":    ({ -4,-33,  4,  1, 1, 1 }),  // 崎嶇山路 — s
    "/d/wudang/tyroad8":    ({ -3,-33,  3,  1, 1, 1 }),  // 桃園小路 — hub
    "/d/wudang/tynroad":    ({ -3,-32,  3,  1, 1, 1 }),  // 桃園小路 — n of tyroad8
    "/d/wudang/tysroad":    ({ -3,-34,  3,  1, 1, 1 }),  // 桃園小路 — s of tyroad8
    "/d/wudang/tyroad9":    ({ -2,-33,  3,  1, 1, 1 }),  // 桃園小路 — e
    "/d/wudang/tyroad10":   ({ -1,-33,  3,  1, 1, 1 }),  // 桃園小路 — hub
    "/d/wudang/tygate1":    ({ -1,-32,  3,  1, 1, 1 }),  // 桃園籬笆 — n of tyroad10
    "/d/wudang/tygate2":    ({ -1,-34,  3,  1, 1, 1 }),  // 桃園木門 — s of tyroad10
    "/d/wudang/tyroad11":   ({  0,-33,  3,  1, 1, 1 }),  // 桃園小路 — e
    "/d/wudang/tyroad12":   ({  1,-33,  3,  1, 1, 1 }),  // 桃園小路 — e
    "/d/wudang/tyroad13":   ({  2,-33,  3,  1, 1, 1 }),  // 桃園 — e
    "/d/wudang/gyroad1":    ({  3,-33,  3,  1, 1, 1 }),  // 果園小路 — e
    "/d/wudang/gyroad2":    ({  4,-33,  3,  1, 1, 1 }),  // 果園 — e (dead end)

    // ══════ Wudang z=2: Summit path ══════
    "/d/wudang/wuyaling":   ({ -3,-30, 11,  1, 1, 1 }),  // 烏鴉嶺 — su from langmeiyuan(z1)
    "/d/wudang/sanlaofeng": ({ -3,-31, 12,  1, 1, 1 }),  // 三老峰
    "/d/wudang/wulaofeng":  ({ -3,-32, 13,  1, 1, 1 }),  // 五老峰
    "/d/wudang/hutouyan":   ({ -3,-33, 14,  1, 1, 1 }),  // 虎頭巖
    "/d/wudang/chaotiangong":({-3,-34, 15,  1, 1, 1 }),  // 朝天宮
    "/d/wudang/huixianqiao":({ -3,-35, 15,  1, 1, 1 }),  // 會仙橋
    "/d/wudang/toutiangate":({ -3,-36, 15,  1, 1, 1 }),  // 頭天門
    "/d/wudang/ertiangate": ({ -3,-37, 16,  1, 1, 1 }),  // 二天門
    "/d/wudang/santiangate":({ -3,-38, 17,  1, 1, 1 }),  // 三天門
    "/d/wudang/jinding":    ({ -3,-39, 18,  1, 1, 1 }),  // 金頂
    "/d/wudang/shierliantai":({-4,-39, 18,  1, 1, 1 }),  // 十二蓮臺 — w of jinding
    "/d/wudang/guanyuntai": ({ -2,-39, 19,  1, 1, 1 }),  // 觀雲臺 — e of jinding
    "/d/wudang/zijincheng": ({ -3,-40, 18,  1, 1, 1 }),  // 紫金城 — s of jinding
    "/d/wudang/jindian":    ({ -3,-41, 18,  1, 1, 1 }),  // 金殿 — s of zijincheng

    // ══════ Wudang z=-1: Nanyan underground maze ══════
    "/d/wudang/nanyan0":    ({ -3,-30, 9,  1, 1, 1 }),  // 南巖宮地下室 — below nanyangong
    "/d/wudang/nanyan1":    ({ -2,-30, 9,  1, 1, 1 }),  // 南巖迷宮 — e
    "/d/wudang/nanyan2":    ({ -4,-30, 9,  1, 1, 1 }),  // 南巖迷宮 — w
    "/d/wudang/nanyan3":    ({ -3,-31, 9,  1, 1, 1 }),  // 南巖迷宮 — s
    "/d/wudang/nanyan4":    ({ -3,-29, 9,  1, 1, 1 }),  // 南巖迷宮 — n

    // ╔═══════════════════════════════════════════════════════════════╗
    // ║  HENSHAN (衡山) — 108 rooms, 9 z-levels (-1 to 7)           ║
    // ║  z=-1: underground caves, heishatan, shanlu9                 ║
    // ║  z=0: Hengyang city, Nanyue temple, approach roads           ║
    // ║  z=1: lower mountain trails, huiyan, cave exits              ║
    // ║  z=2: mid mountain, shuiliandong, scattered peaks            ║
    // ║  z=3: upper mountain (tianzhu, liuyunping, shanlu16)         ║
    // ║  z=4: peaks (zigai, zhurongdian, shilinfeng)                 ║
    // ║  z=5-7: highest approach to Zhurong Peak                     ║
    // ╚═══════════════════════════════════════════════════════════════╝

    // ══════ Hengyang city — main streets (z=0) ══════
    "/d/henshan/hengyang":   ({  0,  0, 0,  1, 1, 1 }),  // 衡陽城 — hub
    "/d/henshan/hengyang1":  ({ -1,  0, 0,  1, 1, 1 }),  // 衡陽西街
    "/d/henshan/hengyang11": ({ -2,  0, 0,  1, 1, 1 }),  // 衡陽西街
    "/d/henshan/hengyang2":  ({  1,  0, 0,  1, 1, 1 }),  // 衡陽東街

    // ══════ Hengyang city — shops & alleys (z=0) ══════
    "/d/henshan/chaguan":    ({  0, -1, 0,  1, 1, 1 }),  // 茶館 — s of hengyang
    "/d/henshan/shop":       ({ -1, -1, 0,  1, 1, 1 }),  // 小店 — s of hengyang1
    "/d/henshan/zahuopu":    ({  1,  1, 0,  1, 1, 1 }),  // 雜貨鋪 — n of hengyang2
    "/d/henshan/majiu":      ({ -2, -1, 0,  1, 1, 1 }),  // 馬廄 — s of hengyang11
    "/d/henshan/lingyinge":  ({ -2,  1, 0,  1, 1, 1 }),  // 鈴音閣 — n of hengyang11
    "/d/henshan/xiaoxiang1": ({  1, -1, 0,  1, 1, 1 }),  // 小巷 — s of hengyang2
    "/d/henshan/xiaoxiang2": ({  1, -2, 0,  1, 1, 1 }),  // 小巷
    "/d/henshan/baihuzhai":  ({  1, -3, 0,  1, 1, 1 }),  // 百狐齋
    "/d/henshan/chating":    ({ -3,  1, 0,  1, 1, 1 }),  // 茶亭 — e of hsroad6

    // ══════ Hengyang city — huiyan upper (z=1) ══════
    "/d/henshan/huiyan":     ({ -1, -1, 1,  1, 1, 1 }),  // 回雁樓 — above shop

    // ══════ Liu Fu mansion (z=0) ══════
    "/d/henshan/liufugate":   ({ -1,  1, 0,  1, 1, 1 }),  // 劉府大門 — n of hengyang1
    "/d/henshan/liufudayuan": ({ -2,  2, 0,  2, 2, 1 }),  // 劉府大院 — 大院 banquet courtyard
    "/d/henshan/liufudating": ({ -2,  4, 0,  1, 1, 1 }),  // 劉府大廳 — n of dayuan
    "/d/henshan/liufueast":   ({ -1,  4, 0,  1, 1, 1 }),  // 東廂房 — e of dating
    "/d/henshan/liufuwest":   ({ -3,  4, 0,  1, 1, 1 }),  // 西廂房 — w of dating

    // ══════ Nanyue Great Temple — south to north (z=0) ══════
    "/d/henshan/lingxingmen": ({  0,  1, 0,  1, 1, 1 }),  // 欞星門 — n of hengyang
    "/d/henshan/kuixingge":   ({  0,  2, 0,  1, 1, 1 }),  // 奎星閣
    "/d/henshan/zhongting":   ({  1,  2, 0,  1, 1, 1 }),  // 鍾亭 — e of kuixingge
    "/d/henshan/zhengchuan":  ({  0,  3, 0,  1, 1, 1 }),  // 正川門
    "/d/henshan/yubeiting":   ({  0,  4, 0,  1, 1, 1 }),  // 御碑亭
    "/d/henshan/jiayingmen":  ({  0,  5, 0,  1, 1, 1 }),  // 嘉應門
    "/d/henshan/yushulou":    ({  0,  6, 0,  1, 1, 1 }),  // 御書樓
    "/d/henshan/dadian":      ({ -1,  7, 0,  2, 1, 1 }),  // 大殿 — 72 pillars, 7 bays wide
    "/d/henshan/houdian":     ({  0,  8, 0,  1, 1, 1 }),  // 後殿
    "/d/henshan/beimen":      ({  0,  9, 0,  1, 1, 1 }),  // 正北門 — mountain starts

    // ══════ Approach roads — east (z=0) ══════
    "/d/henshan/hsroad3":    ({  2,  0, 0,  1, 1, 1 }),  // 黃土路 — ne→hsroad2, w→hengyang2
    "/d/henshan/hsroad2":    ({  3,  1, 0,  1, 1, 1 }),  // 黃土路 — se→yanping, ne→huangshan
    "/d/henshan/hsroad1":    ({  3,  2, 0,  1, 1, 1 }),  // 黃土路 — ne→wudang/wdroad4

    // ══════ Approach roads — west (z=0) ══════
    "/d/henshan/hsroad4":    ({ -3,  0, 0,  1, 1, 1 }),  // 黃土路 — e→hengyang11
    "/d/henshan/hsroad5":    ({ -4,  0, 0,  1, 1, 1 }),  // 林間大道 — w→motianya, su→hsroad9
    "/d/henshan/hsroad6":    ({ -4,  1, 0,  1, 1, 1 }),  // 林間大道 — w→heizhao, sw→tiezhang
    "/d/henshan/hsroad7":    ({ -4,  2, 0,  1, 1, 1 }),  // 林間大道
    "/d/henshan/hsroad8":    ({ -4,  3, 0,  1, 1, 1 }),  // 林間道 — nw→yueyang/nanmen

    // ══════ Nanling pass (z=1) ══════
    "/d/henshan/hsroad9":    ({ -4, -1, 1,  1, 1, 1 }),  // 南嶺山口 — sd→foshan/nanling

    // ══════ Mountain trail — beimen to chidifeng (z=1) ══════
    "/d/henshan/shanlu1":    ({  0, 10, 1,  1, 1, 1 }),  // 山路 — sd→beimen
    "/d/henshan/shanlu2":    ({ -1, 11, 1,  1, 1, 1 }),  // 山路 — nw of shanlu1
    "/d/henshan/shanlu11":   ({  0, 12, 1,  1, 1, 1 }),  // 山路 — ed of chidifeng
    "/d/henshan/shanlu12":   ({  1, 12, 1,  1, 1, 1 }),  // 山路 — eu→shuiliandong

    // ══════ Chidifeng (z=2) ══════
    "/d/henshan/chidifeng":  ({ -1, 12, 2,  1, 1, 1 }),  // 赤帝峰 — sd→shanlu2, ed→shanlu11

    // ══════ Mountain trail — chidifeng north to banshan (z=1-2) ══════
    "/d/henshan/shanlu3":    ({ -1, 13, 1,  1, 1, 1 }),  // 山路 — nd of chidifeng
    "/d/henshan/shanlu4":    ({ -2, 14, 1,  1, 1, 1 }),  // 山路 — nw of shanlu3
    "/d/henshan/banshan":    ({ -2, 15, 2,  1, 1, 1 }),  // 半山亭 — nu from shanlu4

    // ══════ Mountain trail — banshan to shanlu5 (z=2) ══════
    "/d/henshan/shanlu002":  ({ -3, 16, 2,  1, 1, 1 }),  // 山路 — nw of banshan
    "/d/henshan/shanlu001":  ({ -4, 16, 2,  1, 1, 1 }),  // 山路 — w of shanlu002
    "/d/henshan/shanlu5":    ({ -5, 16, 2,  1, 1, 1 }),  // 山路 — hub: w→shanlu6, nw→shanlu13

    // ══════ Mojingtai branch (z=0-2) ══════
    "/d/henshan/shanlu6":    ({ -6, 16, 2,  1, 1, 1 }),  // 山路 — w→shulin1, sd→mojingtai
    "/d/henshan/shulin1":    ({ -7, 16, 2,  1, 1, 1 }),  // 樹林 — w of shanlu6
    "/d/henshan/mojingtai":  ({ -6, 15, 1,  1, 1, 1 }),  // 磨鏡臺 — sd→shanlu8, wu→shanlu7
    "/d/henshan/shanlu8":    ({ -6, 14, 0,  1, 1, 1 }),  // 山路 — sd of mojingtai, su→sansheng
    "/d/henshan/shanlu7":    ({ -7, 15, 2,  1, 1, 1 }),  // 山路 — wu→tianzhu, ed→mojingtai

    // ══════ Tianzhu Peak & Fangguang branch (z=1-3) ══════
    "/d/henshan/tianzhu":    ({ -8, 15, 3,  1, 1, 1 }),  // 天柱峰 — wu from shanlu7
    "/d/henshan/shanlu10":   ({ -9, 15, 2,  1, 1, 1 }),  // 山路 — eu→tianzhu, wd→fangguangsi
    "/d/henshan/fangguangsi":({-10, 15, 1,  1, 1, 1 }),  // 方廣寺 — sd→shanjian
    "/d/henshan/shanjian":   ({-10, 14, 0,  1, 1, 1 }),  // 山澗 — d→heishatan
    "/d/henshan/heishatan":  ({-10, 14,-1,  1, 1, 1 }),  // 黑沙潭 — below shanjian

    // ══════ Fuyansi / Sansheng branch (z=-1 to z=2) ══════
    "/d/henshan/sansheng":   ({ -6, 13, 1,  1, 1, 1 }),  // 三生塔 — su→jigaoming, ed→fuyansi
    "/d/henshan/jigaoming":  ({ -6, 12, 2,  1, 1, 1 }),  // 極高明臺 — su from sansheng
    "/d/henshan/fuyansi":    ({ -5, 13, 0,  1, 1, 1 }),  // 福嚴寺 — sd→shanlu9
    "/d/henshan/shanlu9":    ({ -5, 12,-1,  1, 1, 1 }),  // 山路 — su→nantaisi, nu→fuyansi
    "/d/henshan/nantaisi":   ({ -5, 11, 0,  1, 1, 1 }),  // 南臺寺 — su from shanlu9

    // ══════ Nantianmen area (z=2) ══════
    "/d/henshan/shanlu13":   ({ -6, 17, 2,  1, 1, 1 }),  // 山路 — nw of shanlu5
    "/d/henshan/nantian":    ({ -6, 18, 2,  2, 1, 1 }),  // 南天門 — 3-archway gate, 5-exit hub
    "/d/henshan/denggaotai": ({ -4, 17, 2,  1, 1, 1 }),  // 登高臺 — se of nantian
    "/d/henshan/shiziyan":   ({ -4, 19, 2,  1, 1, 1 }),  // 獅子巖 — ne of nantian
    "/d/henshan/liuyunping": ({ -4, 18, 3,  1, 1, 1 }),  // 流雲坪 — eu of nantian
    "/d/henshan/shilinfeng": ({ -3, 18, 4,  1, 1, 1 }),  // 石廩峰 — eu of liuyunping

    // ══════ Cangjingdian / Furongfeng branch (z=2) ══════
    "/d/henshan/shanlu14":   ({ -6, 19, 2,  1, 1, 1 }),  // 山路 — w→cangjingdian, se→nantian
    "/d/henshan/conglin-1":  ({ -6, 20, 2,  1, 1, 1 }),  // 叢林 — n of shanlu14
    "/d/henshan/cangjingdian":({-7, 19, 2,  1, 1, 1 }),  // 藏經殿 — e→shanlu14
    "/d/henshan/shuzhuangtai":({-7, 18, 2,  1, 1, 1 }),  // 梳妝檯 — s of cangjingdian
    "/d/henshan/furongfeng": ({ -8, 18, 2,  1, 1, 1 }),  // 芙蓉峰 — se→shanlu13

    // ══════ Zhurong Hall area (z=3-4) ══════
    "/d/henshan/wangritai":  ({ -4, 20, 3,  1, 1, 1 }),  // 望日臺 — sd→shiziyan, nu→zhurongdian
    "/d/henshan/zhurongdian":({ -4, 21, 4,  1, 1, 1 }),  // 祝融殿 — Hengshan HQ
    "/d/henshan/wangyuetai": ({ -4, 22, 3,  1, 1, 1 }),  // 望月臺 — nd of zhurongdian
    "/d/henshan/changlang":  ({ -3, 21, 4,  1, 1, 1 }),  // 長廊 — e of zhurongdian
    "/d/henshan/kefang":     ({ -3, 22, 4,  1, 1, 1 }),  // 客房 — n of changlang
    "/d/henshan/henshan_chufang":({ -2, 22, 4, 1, 1, 1 }),  // 廚房 — ne of changlang

    // ══════ Zhurong Peak ascent (z=5-7) ══════
    "/d/henshan/shanlu003":  ({ -5, 21, 5,  1, 1, 1 }),  // 山路 — wu of zhurongdian
    "/d/henshan/shanlu004":  ({ -6, 21, 6,  1, 1, 1 }),  // 山路 — wu of shanlu003
    "/d/henshan/zhurongfeng":({ -7, 21, 7,  1, 1, 1 }),  // 祝融峰 — highest peak

    // ══════ Shuiliandong → Zigai path (z=2-4) ══════
    "/d/henshan/shuiliandong":({ 2, 12, 2,  1, 1, 1 }),  // 水簾洞外 — jump→inhole
    "/d/henshan/shanlu15":   ({  3, 13, 2,  1, 1, 1 }),  // 山路 — ne of shuiliandong
    "/d/henshan/shanlu16":   ({  3, 14, 3,  1, 1, 1 }),  // 山路 — nu from shanlu15
    "/d/henshan/zigai":      ({  3, 15, 4,  1, 1, 1 }),  // 紫蓋峰 — nu from shanlu16

    // ══════ Waterfall cave system (z=-1) ══════
    "/d/henshan/inhole":     ({  2, 12,-1,  1, 1, 1 }),  // 水簾洞外洞 — behind waterfall
    "/d/henshan/inhole1":    ({  2, 13,-1,  1, 1, 1 }),  // 水簾洞內 — enter from inhole
    "/d/henshan/inhole2":    ({  1, 14,-1,  1, 1, 1 }),  // 水簾洞內 — nw branch (fire→exits)
    "/d/henshan/inhole3":    ({  3, 14,-1,  1, 1, 1 }),  // 水簾洞內 — ne branch (→furong)

    // ══════ Zigai cave maze (z=-1) ══════
    "/d/henshan/zigai1":     ({  0, 14,-1,  1, 1, 1 }),  // 水蓮洞內 — w of inhole2
    "/d/henshan/zigai2":     ({  1, 15,-1,  1, 1, 1 }),  // 水蓮洞內 — n of inhole2
    "/d/henshan/zigai3":     ({  1, 16,-1,  1, 1, 1 }),  // 水蓮洞內 — n of zigai2
    "/d/henshan/zigai4":     ({ -1, 14,-1,  1, 1, 1 }),  // 水蓮洞內 — w of zigai1 (zou→outzigai)
    "/d/henshan/outzigai":   ({ -2, 14,-1,  1, 1, 1 }),  // 水蓮洞內 — dead end, climb→outzigai1

    // ══════ Zigai cave exit & cliff (z=0) ══════
    "/d/henshan/outzigai1":  ({ -2, 14, 0,  1, 1, 1 }),  // 突石上 — push→zigaihole
    "/d/henshan/zigaihole":  ({ -2, 15, 0,  1, 1, 1 }),  // 紫蓋仙洞 — n→xuanya
    "/d/henshan/xuanya":     ({ -2, 16, 0,  1, 1, 1 }),  // 懸崖邊 — climb→zigai, jump→xuanyadi

    // ══════ Cliff bottom & tree (z=-1 to z=1) ══════
    "/d/henshan/xuanyadi":   ({ -2, 16,-1,  1, 1, 1 }),  // 懸崖底 — below xuanya
    "/d/henshan/tianquan-hole":({-3, 16,-1,  1, 1, 1 }),  // 天泉洞 — out→xuanyadi
    "/d/henshan/ontree":     ({ -1, 16, 0,  1, 1, 1 }),  // 古樹上 — climb from xuanyadi
    "/d/henshan/ontree2":    ({ -1, 16, 1,  1, 1, 1 }),  // 古樹頂 — swing→zhushen cave

    // ══════ Zhushen cave (z=1) ══════
    "/d/henshan/outzhushendong":({ -2, 17, 1, 1, 1, 1 }),  // 諸神仙洞 — climb→shilinfeng
    "/d/henshan/inzhushendong": ({ -4, 17, 1, 2, 1, 1 }),  // 諸神仙洞內 — spacious cavern, wushen-jian

    // ══════ Furong cave (z=1, near furongfeng) ══════
    "/d/henshan/furong":     ({ -9, 18, 1,  1, 1, 1 }),  // 芙蓉洞外 — one-way from inhole3
    "/d/henshan/furong1":    ({ -8, 18, 1,  1, 1, 1 }),  // 芙蓉洞 — climb→furongfeng

    // ╔═══════════════════════════════════════════════════════════════╗
    // ║  XIANGYANG (襄陽) — 135 rooms, z=0 to z=10                  ║
    // ║  z=0: walled city, streets, compounds, outside areas         ║
    // ║  z=1-3: city wall stairs (24 rooms)                          ║
    // ║  z=4: wall tops (8 rooms)                                    ║
    // ║  z=1-10: east arrow tower (10 rooms)                         ║
    // ╚═══════════════════════════════════════════════════════════════╝

    // ══════ Central square (z=0) ══════
    "/d/xiangyang/guangchang":    ({  0,  0, 0,  2, 2, 1 }),  // 中央廣場 — 2×2 plaza hub
    "/d/xiangyang/anfupailou":    ({  1,  2, 0,  1, 1, 1 }),  // 安撫府牌樓 — n of guangchang
    "/d/xiangyang/anfugate":      ({  1,  3, 0,  1, 1, 1 }),  // 安撫使衙門 — dead end

    // ══════ East main street (z=0) ══════
    "/d/xiangyang/eastjie1":      ({  2,  0, 0,  1, 1, 1 }),  // 東大街 — 寬闊
    "/d/xiangyang/eastjie2":      ({  4,  0, 0,  1, 1, 1 }),  // 東大街
    "/d/xiangyang/eastjie3":      ({  6,  0, 0,  1, 1, 1 }),  // 東大街 — 寬闊

    // ══════ West main street (z=0) ══════
    "/d/xiangyang/westjie1":      ({ -1,  0, 0,  1, 1, 1 }),  // 西大街 — 寬闊
    "/d/xiangyang/westjie2":      ({ -3,  0, 0,  1, 1, 1 }),  // 西大街
    "/d/xiangyang/westjie3":      ({ -5,  0, 0,  1, 1, 1 }),  // 西大街 — 寬闊

    // ══════ South main street (z=0) ══════
    "/d/xiangyang/southjie1":     ({  0, -2, 0,  1, 1, 1 }),  // 南大街 — 寬闊
    "/d/xiangyang/southjie2":     ({  0, -3, 0,  1, 1, 1 }),  // 南大街
    "/d/xiangyang/southjie3":     ({  0, -4, 0,  1, 1, 1 }),  // 南大街

    // ══════ East gates (z=0) ══════
    "/d/xiangyang/eastgate1":     ({  7,  0, 0,  1, 1, 1 }),  // 青龍內門 — up→eastlou1(quest)
    "/d/xiangyang/eastgate2":     ({  8,  0, 0,  1, 1, 1 }),  // 青龍外門 — e→city2/yidao

    // ══════ West gates (z=0) ══════
    "/d/xiangyang/westgate1":     ({ -6,  0, 0,  1, 1, 1 }),  // 白虎內門
    "/d/xiangyang/westgate2":     ({ -7,  0, 0,  1, 1, 1 }),  // 白虎外門 — w→city2/yidao1

    // ══════ South gates (z=0) ══════
    "/d/xiangyang/southgate1":    ({  0, -5, 0,  1, 1, 1 }),  // 朱雀內門
    "/d/xiangyang/southgate2":    ({  0, -6, 0,  1, 1, 1 }),  // 朱雀外門

    // ══════ North streets & gates (z=0) ══════
    "/d/xiangyang/dingzi":        ({  0,  3, 0,  1, 1, 1 }),  // 丁字街口 — T-junction
    "/d/xiangyang/northjie":      ({  0,  4, 0,  1, 1, 1 }),  // 北大街 — 寬闊
    "/d/xiangyang/northgate1":    ({  0,  5, 0,  1, 1, 1 }),  // 玄武內門
    "/d/xiangyang/northgate2":    ({  0,  6, 0,  1, 1, 1 }),  // 玄武外門

    // ══════ Inner ring — east side (z=0) ══════
    "/d/xiangyang/eastroad1":     ({  4,  1, 0,  1, 1, 1 }),  // 東內大街 — n of eastjie2
    "/d/xiangyang/eastroad2":     ({  4,  2, 0,  1, 1, 1 }),  // 東內大街

    // ══════ Inner ring — west side (z=0) ══════
    "/d/xiangyang/westroad1":     ({ -3,  1, 0,  1, 1, 1 }),  // 西內大街 — n of westjie2
    "/d/xiangyang/westroad2":     ({ -3,  2, 0,  1, 1, 1 }),  // 西內大街

    // ══════ Inner ring — north crossbar (z=0) ══════
    "/d/xiangyang/jiekou1":       ({ -3,  3, 0,  1, 1, 1 }),  // 大街口 — NW intersection
    "/d/xiangyang/northroad1":    ({ -2,  3, 0,  1, 1, 1 }),  // 北內大街
    "/d/xiangyang/northroad2":    ({  3,  3, 0,  1, 1, 1 }),  // 北內大街
    "/d/xiangyang/jiekou2":       ({  4,  3, 0,  1, 1, 1 }),  // 大街口 — NE intersection

    // ══════ Shops off east street (z=0) ══════
    "/d/xiangyang/yaopu":         ({  2, -1, 0,  1, 1, 1 }),  // 藥鋪 — s of eastjie1
    "/d/xiangyang/jiedao":        ({  4, -1, 0,  1, 1, 1 }),  // 街道 — s of eastjie2
    "/d/xiangyang/minju1":        ({  5, -1, 0,  1, 1, 1 }),  // 民居 — e of jiedao
    "/d/xiangyang/minju2":        ({  3, -1, 0,  1, 1, 1 }),  // 民居 — w of jiedao
    "/d/xiangyang/mujiang":       ({  6, -1, 0,  1, 1, 1 }),  // 木匠鋪 — s of eastjie3
    "/d/xiangyang/biaoju":        ({  5,  1, 0,  1, 1, 1 }),  // 福威鏢局 — 宏偉, e of eastroad1
    "/d/xiangyang/bingying2":     ({  6,  1, 0,  1, 1, 1 }),  // 兵營 — n of eastjie3
    "/d/xiangyang/zhonglie":      ({  5,  2, 0,  1, 1, 1 }),  // 忠烈祠 — e of eastroad2

    // ══════ Shops off west street (z=0) ══════
    "/d/xiangyang/dangpu":        ({ -1, -1, 0,  1, 1, 1 }),  // 當鋪 — s of westjie1
    "/d/xiangyang/dajiaochang":   ({ -5, -1, 0,  1, 1, 1 }),  // 大校場 — s of westjie3
    "/d/xiangyang/bingying4":     ({ -5,  1, 0,  1, 1, 1 }),  // 兵營 — n of westjie3
    "/d/xiangyang/kedian":        ({ -4,  1, 0,  1, 1, 1 }),  // 襄陽客棧 — w of westroad1
    "/d/xiangyang/shudian":       ({ -4,  2, 0,  1, 1, 1 }),  // 書店 — w of westroad2

    // ══════ Shops off south street (z=0) ══════
    "/d/xiangyang/xuetang":       ({  1, -2, 0,  1, 1, 1 }),  // 學堂 — e of southjie1
    "/d/xiangyang/qianzhuang":    ({ -1, -2, 0,  1, 1, 1 }),  // 錢莊 — w of southjie1
    "/d/xiangyang/nixianglou":    ({  1, -3, 0,  1, 1, 1 }),  // 覓香樓 — e of southjie2
    "/d/xiangyang/duchang":       ({ -1, -3, 0,  1, 1, 1 }),  // 賭場 — w of southjie2
    "/d/xiangyang/tiejiangpu":    ({  1, -4, 0,  1, 1, 1 }),  // 兵器鋪 — e of southjie3
    "/d/xiangyang/bingying3":     ({ -1, -4, 0,  1, 1, 1 }),  // 兵營 — w of southjie3

    // ══════ Shops off north streets (z=0) ══════
    "/d/xiangyang/chaguan":       ({  1,  4, 0,  1, 1, 1 }),  // 茶館 — e of northjie
    "/d/xiangyang/bingying1":     ({ -1,  4, 0,  1, 1, 1 }),  // 兵營 — w of northjie
    "/d/xiangyang/xinluofang":    ({ -2,  4, 0,  1, 1, 1 }),  // 新羅坊 — n of northroad1
    "/d/xiangyang/majiu":         ({  3,  4, 0,  1, 1, 1 }),  // 馬廄 — n of northroad2

    // ══════ Jiangjun mansion (z=0) ══════
    "/d/xiangyang/jiangjungate":  ({  2,  1, 0,  1, 1, 1 }),  // 將軍府大門 — n of eastjie1
    "/d/xiangyang/jiangjunyuan":  ({  2,  2, 0,  1, 1, 1 }),  // 將軍府大院
    "/d/xiangyang/jiangjuntang":  ({  2,  3, 0,  1, 1, 1 }),  // 將軍府大堂 — dead end

    // ══════ Juyi compound (z=0) ══════
    "/d/xiangyang/juyiyuan":      ({ -3, -1, 0,  1, 1, 1 }),  // 大院 — s of westjie2
    "/d/xiangyang/juyilianwu1":   ({ -2, -1, 0,  1, 1, 1 }),  // 練功場 — e of juyiyuan
    "/d/xiangyang/juyilianwu2":   ({ -4, -1, 0,  1, 1, 1 }),  // 練功場 — w of juyiyuan
    "/d/xiangyang/juyilang":      ({ -3, -2, 0,  1, 1, 1 }),  // 水上走廊 — s of juyiyuan
    "/d/xiangyang/juyihuayuan":   ({ -3, -3, 0,  1, 1, 1 }),  // 大花園 — s of juyilang
    "/d/xiangyang/juyifemale":    ({ -2, -3, 0,  1, 1, 1 }),  // 女客房 — e of huayuan (gender)
    "/d/xiangyang/juyimale":      ({ -4, -3, 0,  1, 1, 1 }),  // 男客房 — w of huayuan (gender)
    "/d/xiangyang/juyichufang":   ({ -3, -4, 0,  1, 1, 1 }),  // 廚房 — s of huayuan
    "/d/xiangyang/juyiwupin":     ({ -2, -4, 0,  1, 1, 1 }),  // 物品房 — se of huayuan

    // ══════ Alleys & residential (z=0) ══════
    "/d/xiangyang/hutong1":       ({ -4,  3, 0,  1, 1, 1 }),  // 衚衕 — w of jiekou1
    "/d/xiangyang/hutong2":       ({ -3,  4, 0,  1, 1, 1 }),  // 衚衕 — n of jiekou1, knock→hbd
    "/d/xiangyang/xiaorong1":     ({  5,  3, 0,  1, 1, 1 }),  // 衚衕 — e of jiekou2
    "/d/xiangyang/xiaorong2":     ({  4,  4, 0,  1, 1, 1 }),  // 衚衕 — n of jiekou2, dead end

    // ══════ Factions (z=0) ══════
    "/d/xiangyang/hbd_xyfb":      ({ -3,  5, 0,  1, 1, 1 }),  // 黑白道襄陽分壇 — via hutong2 knock
    "/d/xiangyang/wjb_damen":     ({  5,  4, 0,  1, 1, 1 }),  // 無極幫門前 — n of xiaorong1
    "/d/xiangyang/wjb_dating":    ({  5,  5, 0,  1, 1, 1 }),  // 無極幫總舵 — faction HQ
    "/d/xiangyang/xym_zb":        ({  6,  3, 0,  1, 1, 1 }),  // 俠義盟大門 — w→jiekou2 (asymmetric)
    "/d/xiangyang/xym_dating":    ({  6,  4, 0,  1, 1, 1 }),  // 俠義盟襄陽總舵 — faction HQ

    // ══════ Outside — south grasslands (z=0) ══════
    "/d/xiangyang/caodi4":        ({  1, -6, 0,  1, 1, 1 }),  // 草地 — e of southgate2
    "/d/xiangyang/caodi5":        ({ -1, -6, 0,  1, 1, 1 }),  // 草地 — w of southgate2
    "/d/xiangyang/caodi6":        ({  0, -7, 0,  1, 1, 1 }),  // 草地 — s→wudang/wdroad5

    // ══════ Outside — north grasslands (z=0) ══════
    "/d/xiangyang/caodi1":        ({  1,  6, 0,  1, 1, 1 }),  // 草地 — e of northgate2
    "/d/xiangyang/caodi2":        ({ -1,  6, 0,  1, 1, 1 }),  // 草地 — w of northgate2
    "/d/xiangyang/caodi3":        ({  0,  7, 0,  1, 1, 1 }),  // 草地 — n→luoyang/guandaos6

    // ══════ Outside — west road (z=0) ══════
    "/d/xiangyang/outwroad1":     ({ -7,  1, 0,  1, 1, 1 }),  // 青石大道 — se→westgate1

    // ══════ Outside — east maze (z=0) ══════
    "/d/xiangyang/east_out1":     ({ 10,  0, 0,  1, 1, 1 }),  // 城外空地 — circular chain start
    "/d/xiangyang/east_out2":     ({ 11,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out3":     ({ 12,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out4":     ({ 13,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out5":     ({ 14,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out6":     ({ 15,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out7":     ({ 16,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out8":     ({ 17,  0, 0,  1, 1, 1 }),  // 城外空地
    "/d/xiangyang/east_out9":     ({ 18,  0, 0,  1, 1, 1 }),  // 城外空地 — wraps→east_out1

    // ══════ Hunan road — distant path (z=0) ══════
    "/d/xiangyang/hunanroad1":    ({ -1, -7, 0,  1, 1, 1 }),  // 土路 — e→caodi6, sw→hunanroad2
    "/d/xiangyang/hunanroad2":    ({ -2, -8, 0,  1, 1, 1 }),  // 土路 — ne→hunanroad1
    "/d/xiangyang/lx":            ({ -2, -9, 0,  1, 1, 1 }),  // 瀘溪 — dead end, tiezhang area

    // ══════ East wall stairs z=1 ══════
    "/d/xiangyang/walle1":        ({  7, -1, 1,  1, 1, 1 }),  // 石階 — southup from eastgate1
    "/d/xiangyang/walle2":        ({  7,  1, 1,  1, 1, 1 }),  // 石階 — northup from eastgate1

    // ══════ North wall stairs z=1 ══════
    "/d/xiangyang/walln1":        ({  1,  5, 1,  1, 1, 1 }),  // 石階 — eastup from northgate1
    "/d/xiangyang/walln2":        ({ -1,  5, 1,  1, 1, 1 }),  // 石階 — westup from northgate1

    // ══════ South wall stairs z=1 ══════
    "/d/xiangyang/walls1":        ({ -1, -5, 1,  1, 1, 1 }),  // 石階 — westup from southgate1
    "/d/xiangyang/walls2":        ({  1, -5, 1,  1, 1, 1 }),  // 石階 — eastup from southgate1

    // ══════ West wall stairs z=1 ══════
    "/d/xiangyang/wallw1":        ({ -6,  1, 1,  1, 1, 1 }),  // 石階 — northup from westgate1
    "/d/xiangyang/wallw2":        ({ -6, -1, 1,  1, 1, 1 }),  // 石階 — southup from westgate1

    // ══════ East wall stairs z=2 ══════
    "/d/xiangyang/walle3":        ({  7, -2, 2,  1, 1, 1 }),  // 石階 — southup from walle1
    "/d/xiangyang/walle4":        ({  7,  2, 2,  1, 1, 1 }),  // 石階 — northup from walle2

    // ══════ North wall stairs z=2 ══════
    "/d/xiangyang/walln3":        ({  2,  5, 2,  1, 1, 1 }),  // 石階 — eastup from walln1
    "/d/xiangyang/walln4":        ({ -2,  5, 2,  1, 1, 1 }),  // 石階 — westup from walln2

    // ══════ South wall stairs z=2 ══════
    "/d/xiangyang/walls3":        ({ -2, -5, 2,  1, 1, 1 }),  // 石階 — westup from walls1
    "/d/xiangyang/walls4":        ({  2, -5, 2,  1, 1, 1 }),  // 石階 — eastup from walls2

    // ══════ West wall stairs z=2 ══════
    "/d/xiangyang/wallw3":        ({ -6,  2, 2,  1, 1, 1 }),  // 石階 — northup from wallw1
    "/d/xiangyang/wallw4":        ({ -6, -2, 2,  1, 1, 1 }),  // 石階 — southup from wallw2

    // ══════ East wall stairs z=3 ══════
    "/d/xiangyang/walle5":        ({  7, -3, 3,  1, 1, 1 }),  // 石階 — southup from walle3
    "/d/xiangyang/walle6":        ({  7,  3, 3,  1, 1, 1 }),  // 石階 — northup from walle4

    // ══════ North wall stairs z=3 ══════
    "/d/xiangyang/walln5":        ({  3,  5, 3,  1, 1, 1 }),  // 石階 — eastup from walln3
    "/d/xiangyang/walln6":        ({ -3,  5, 3,  1, 1, 1 }),  // 石階 — westup from walln4

    // ══════ South wall stairs z=3 ══════
    "/d/xiangyang/walls5":        ({ -3, -5, 3,  1, 1, 1 }),  // 石階 — westup from walls3
    "/d/xiangyang/walls6":        ({  3, -5, 3,  1, 1, 1 }),  // 石階 — eastup from walls4

    // ══════ West wall stairs z=3 ══════
    "/d/xiangyang/wallw5":        ({ -6,  3, 3,  1, 1, 1 }),  // 石階 — northup from wallw3
    "/d/xiangyang/wallw6":        ({ -6, -3, 3,  1, 1, 1 }),  // 石階 — southup from wallw4

    // ══════ Wall tops z=4 — corner-connected ring ══════
    "/d/xiangyang/walle7":        ({  7, -4, 4,  1, 1, 1 }),  // 東城頭 — SE, sw→walls8
    "/d/xiangyang/walle8":        ({  7,  4, 4,  1, 1, 1 }),  // 東城頭 — NE, nw→walln7
    "/d/xiangyang/walln7":        ({  4,  5, 4,  1, 1, 1 }),  // 北城頭 — NE, se→walle8
    "/d/xiangyang/walln8":        ({ -4,  5, 4,  1, 1, 1 }),  // 北城頭 — NW, sw→wallw7
    "/d/xiangyang/walls7":        ({ -4, -5, 4,  1, 1, 1 }),  // 南城頭 — SW, nw→wallw8
    "/d/xiangyang/walls8":        ({  4, -5, 4,  1, 1, 1 }),  // 南城頭 — SE, ne→walle7
    "/d/xiangyang/wallw7":        ({ -6,  4, 4,  1, 1, 1 }),  // 西城頭 — NW, ne→walln8
    "/d/xiangyang/wallw8":        ({ -6, -4, 4,  1, 1, 1 }),  // 西城頭 — SW, se→walls7

    // ══════ East arrow tower z=1–10 ══════
    "/d/xiangyang/eastlou1":      ({  7,  0, 1,  1, 1, 1 }),  // 城東箭樓 — above eastgate1
    "/d/xiangyang/eastlou2":      ({  7,  0, 2,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou3":      ({  7,  0, 3,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou4":      ({  7,  0, 4,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou5":      ({  7,  0, 5,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou6":      ({  7,  0, 6,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou7":      ({  7,  0, 7,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou8":      ({  7,  0, 8,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou9":      ({  7,  0, 9,  1, 1, 1 }),  // 城東箭樓
    "/d/xiangyang/eastlou10":     ({  7,  0,10,  1, 1, 1 }),  // 城東箭樓 — top floor
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

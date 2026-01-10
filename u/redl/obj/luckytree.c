// This program is a part of NITAN MudLIB
// redl 2013/12/23
#include <ansi.h>
inherit ITEM;

#define R_LEVEL 10
#define R_ONLINEDAY 1
#define SEND_NUM 28

void post_channel(string arg);
int gf3query(string qq);

mapping *giftlists = ({ //amount為每100人時派發的數量
//level 1，重要的節日才開
    ([
        "id": "xunzhang",
        "level": 1,
        "file": "/clone/medal/daomu_xunzhang",
        "amount": 1
    ]),
    ([
        "id": "ntb",    //100泥潭幣
        "level": 1,
        "file": "/u/redl/npc/obj/ntb",
        "amount": 10
    ]),
//level 2，大的慶祝活動開
    ([
        "id": "ntb",    //100泥潭幣
        "level": 2,
        "file": "/u/redl/npc/obj/ntb",
        "amount": 3
    ]),
    ([
        "id": "xunzhang",
        "level": 2,
        "file": "/clone/medal/diamond_xunzhang",
        "amount": 6
    ]),
    ([
        "id": "slsj",   //聖靈水晶，刺激對裝備系統的強化熱情
        "level": 2,
        "file": "/clone/goods/shengling_crystal",
        "amount": 8
    ]),
    ([
        "id": "qhsj",   //強化水晶
        "level": 2,
        "file": "/clone/goods/qianghua_crystal",
        "amount": 7
    ]),
    ([
        "id": "jll",    //九龍神火爐，大米用品，幾乎沒人願意在它上面花錢
        "level": 2,
        "file": "/clone/goods/jiulonglu",
        "amount": 6
    ]),
    ([
        "id": "ryj",    //日月鏡，願意買的人少
        "level": 2,
        "file": "/clone/goods/riyue-jing",
        "amount": 3
    ]),
    ([
        "id": "byh",    //白玉笏
        "level": 2,
        "file": "/d/dongtian/obj/baiyuhu",
        "amount": 4
    ]),
//level 3，小的慶祝活動或者節日開
    ([
        "id": "xunzhang",
        "level": 3,
        "file": "/clone/medal/vip_xunzhang",
        "amount": 7
    ]),
    ([
        "id": "dtzb1",  //神器動態裝備或者寶石
        "level": 3,
        "file": "",
        "amount": 12
    ]),
    ([
        "id": "ldb",    //六帝幣，洞天持續消耗品，略可以多發
        "level": 3,
        "file": "/d/dongtian/obj/liudibi",
        "amount": 9
    ]),
    ([
        "id": "wm",     //無名之物
        "level": 3,
        "file": "/clone/goods/noname",
        "amount": 2
    ]),
    ([
        "id": "xzx",    //勳章箱子，隨機開得勳章，可以多發
        "level": 3,
        "file": "/clone/goods/xunzhang_xiang",
        "amount": 13
    ]),
    ([
        "id": "ly2",    //龍元2
        "level": 3,
        "file": "/clone/goods/dragon_soul2",
        "amount": 3
    ]),
    ([
        "id": "fhm",    //芳華木
        "level": 3,
        "file": "/u/redl/obj/fanghuamu",
        "amount": 6
    ]),
    ([
        "id": "hytj",   //雞肋，寰宇天晶，給捨不得花錢的玩家一點盼頭
        "level": 3,
        "file": "/clone/goods/tianjing",
        "amount": 8
    ]),
    ([
        "id": "rune26",
        "level": 3,
        "file": "/clone/tessera/rune26",
        "amount": 60
    ]),
    ([
        "id": "cms",    //冊馬石
        "level": 3,
        "file": "/clone/goods/cemashi",
        "amount": 7
    ]),
    ([
        "id": "taozhuang",  //幸運女神
        "level": 3,
        "file": "/clone/goods/luck_neck",
        "amount": 17
    ]),
    ([
        "id": "taozhuang",  //幸運女神
        "level": 3,
        "file": "/clone/goods/luck_charm",
        "amount": 17
    ]),
    ([
        "id": "taozhuang",  //幸運女神
        "level": 3,
        "file": "/clone/goods/luck_ring",
        "amount": 17
    ]),
//level 4，如果想開，那就開吧
    ([
        "id": "xunzhang",
        "level": 4,
        "file": "/clone/medal/yongshi_xunzhang",
        "amount": 8
    ]),
    ([
        "id": "rune14",
        "level": 4,
        "file": "/clone/tessera/rune14",
        "amount": 189
    ]),
    ([
        "id": "zyw",    //鎮獄丸
        "level": 4,
        "file": "/clone/fam/max/zhenyu",
        "amount": 59
    ]),
    ([
        "id": "ljd",    //龍甲丹
        "level": 4,
        "file": "/clone/fam/max/longjia",
        "amount": 119
    ]),
    ([
        "id": "yqw",    //玉清丸
        "level": 4,
        "file": "/clone/medicine/yuqingwan",
        "amount": 161
    ]),
    ([
        "id": "wxts",   //萬象天書
        "level": 4,
        "file": "/d/dongtian/obj/wanxiangbook",
        "amount": 184
    ]),
/*
 * "id"                    :                       "qljp",//千兩金票
 * "level"                 :                       4,
 * "file"                  :                       "/clone/money/thousand-gold",
 * "amount"                :                       200
 * ]),*/
    ([
        "id": "bs1",
        "level": 4,
        "file": "/clone/tessera/mdiamond",
        "amount": 40
    ]),
    ([
        "id": "bs2",
        "level": 4,
        "file": "/clone/tessera/memerald",
        "amount": 40
    ]),
    ([
        "id": "bs3",
        "level": 4,
        "file": "/clone/tessera/msapphire",
        "amount": 40
    ]),
    ([
        "id": "bs4",
        "level": 4,
        "file": "/clone/tessera/mruby",
        "amount": 40
    ]),
    ([
        "id": "bs5",
        "level": 4,
        "file": "/clone/tessera/mtopaz",
        "amount": 40
    ]),
    ([
        "id": "dtzb2",  //傳說動態裝備或者寶石
        "level": 4,
        "file": "",
        "amount": 171
    ])
});

void set_giftlists() {
    int sizeu = sizeof(users());
    int lv = query("gift_level");
    mapping tob, gob, *gls = ({});
    string tname;

    set("send_items_count", 0);
    foreach (gob in giftlists) {
        if (lv <= gob["level"]) {
            tob = copy(gob);
            tname = tob["file"];
            if (!tname || tname =="") {
                if (tob["id"]=="dtzb1")
                    tname = BRED HIW "神器或寶石" NOR;
                else if (tob["id"]=="dtzb2")
                    tname = HIY "傳說或寶石" NOR;
            } else {
                tname = load_object(tname)->name();
            }
            tob += (["name": tname]);
            tob["amount"] = to_int(tob["amount"] * (sizeu / 100.00));   //wiz start時的玩家數才為發放的比例。
            if (tob["amount"]<1) tob["amount"] = 1;
            addn("send_items_count", tob["amount"]);
            gls += ({ tob });
        }
    }

    set("gift_items", gls);
}

int send_giftlists() {
    object usr, *can_send_users = ({});
    int userscount = 0, rday, rlv, aflag, isends = SEND_NUM;
    mapping gob, *gls;
    object tob;
    string msg, tname;
    int i, rate, totalrate, rndrate, *rates;

    gls = query("gift_items");
    if (undefinedp(gls) || !gls || !sizeof(gls)) { //禮物已經發完
        delete("start_at_time");
        return 1;
    }

    rday = query("gift_require_onlineday") * 86400;
    rlv = query("gift_require_level");

    foreach (usr in users()) {
        if (!playerp(usr)) continue;
        if (!interactive(usr)) continue;
        if (wizardp(usr)) continue;
        if (query("online_time", usr) < rday) continue;
        if (query("level", usr) < rlv) continue;
        userscount ++;
        aflag = query("all_users/" + query("id", usr));
        if (aflag) {
            set("all_users/" + query("id", usr), aflag - 1);
        } else {
            can_send_users += ({ usr });
        }
    }

    while (isends) {
        if (!sizeof(can_send_users)) break;
        usr = can_send_users[random(sizeof(can_send_users))];
        if (!sizeof(gls)) break;
        //gob = gls[random(sizeof(gls))];

        //圓桌
        totalrate = 0;
        rates = ({});
        for(i = 0; i<sizeof(gls); i++) {
            rate = gls[i]["amount"];
            totalrate += rate;
            rates += ({ rate });
        }
        rndrate = random(totalrate);
        totalrate = 0;

        for(i = 0; i<sizeof(rates); i++) {
            //write("totalrate:" + (string)totalrate + "\n");
            if (rndrate >= totalrate && rndrate < (totalrate + rates[i])) {
                gob = gls[i];
                //write(HIY + "rndrate:" + (string)rndrate + "<" + (string)(totalrate + rates[i]) + "\n" + NOR);
                break;
            }
            totalrate += rates[i];
        }

        //DEBUG_CHANNEL(NOR + HIG + "  --第" + (string)isends + "人: \n" + NOR);
        isends--;
        if (usr && gob && objectp(usr) && mapp(gob)) {
            can_send_users -= ({ usr });
            addn("all_users/" + query("id", usr), userscount / SEND_NUM / 2);
            gob["amount"] -= 1;

            tname = gob["file"];
            if (!tname || tname =="") {
                if (gob["id"]=="dtzb1")
                    tob = EQUIPMENT_D->create_dynamic("", 100, 600);
                else if (gob["id"]=="dtzb2")
                    tob = EQUIPMENT_D->create_dynamic("", 80, 500);
            } else {
                tob = new(tname);
                if (gob["id"]=="wxts") {
                    set("no_open_msg", 1, tob);
                    tob->do_open(query("id", tob));
                }
                if (gob["id"]=="taozhuang") {
                    set("bindable", 2, tob);
                }
                if (gob["id"]=="ntb") {
                    log_file("static/yangyong3", sprintf("%s 幸運之樹 -> 百元泥潭幣, 獲得者( %s )\n", TIME_D->replace_ctime(time()), query("id", usr)));
                }
            }

            tname = NOR + (
                (query("colorname", tob)) ? query("colorname", tob) : query("name", tob)
            ) + NOR;
            //NOR + "(" + query("id", tob) + ")" + NOR;

            if (tob && tob->move(usr)) {
                //if (!msg) msg = NOR + HIG + query("name", usr) + "(" + query("id", usr) + ")" + "得到" + tname + NOR;
                //else msg += "、" + NOR + HIG + query("name", usr) + "(" + query("id", usr) + ")" + "得到" + tname + NOR;
                if (!msg) msg = NOR + HIG + query("name", usr) + "得到" + tname + NOR;
                else msg += "、" + NOR + HIG + query("name", usr) + "得到" + tname + NOR;
                tell_object(usr, NOR + HIG + "你獲得了" + name() + NOR + HIG + "贈送的" + tname + NOR + HIG + "。" + HIK + "    ( tune news可打開頻道 )\n" + NOR);
            } else {
                destruct(tob);
            }
            //DEBUG_CHANNEL(NOR + query("id",usr) + "獲得" + gob["name"] + "\n 剩餘：" + (string)gob["amount"] + "個\n" + NOR);
            if (!gob["amount"]) {
                //DEBUG_CHANNEL(NOR + HIY + ">>>註銷" + gob["name"] + "\n" + NOR);
                gls -= ({ gob });
            }

            continue;
        }
    }

    if (msg) post_channel(name() + NOR + HIC + "一刷，天外" + chinese_number(SEND_NUM) + "顆星斗上奇寶紛紛墜落。\n" + sort_msg("    " + msg + "。\n", 100));

    set("gift_items", gls);
    return 1;
}

string query_giftlists() {
    string msg = "";
    mapping gob, *gls = query("gift_items");
    foreach (gob in gls) {
        msg += NOR + gob["name"] + NOR + WHT + "(" + (string)(gob["amount"]) + "件) " + NOR;
    }
    return sort_msg(msg, 60);
}

string long() {
    string msg;
    int start_time = query("start_at_time");
    object me = this_player();

    if (query("look_time") > time() && wiz_level(me) < 6) {
        return query("longx") + HIK + "圍觀的人太多，你等會兒再擠吧。\n" + NOR;
    }
    set("look_time", time() + 3 + random(3));
    msg = query("longx");
    if (query("qqgroup/gift")) { // && query("qqgroup/keys") && sizeof(query("qqgroup/keys"))) {
            if (query("gf3_flag"))
            msg += HIG "(如果你找wiz登記了QQ號，想領取" + query("qqgroup/giftname") + HIG + "請輸入：input 你的QQ號) " HIK + "(注意負重)\n" + NOR;
        else
            msg += HIG "(如果你從QQ獲得了序號，想領取" + query("qqgroup/giftname") + HIG + "請輸入：input 序號) " HIK + "(剩餘" + HIY + (string)sizeof(query("qqgroup/keys")) + HIK + "件，注意負重)\n" + NOR;
    }
    if (start_time) {
        if (start_time > time()) {
            msg += NOR + " 仙界定於【" + (string)((start_time - time()) / 60) + "】分鐘後發送禮物，隨機派送給在線玩家，禮物清單如下：\n" + NOR;
        } else {
            msg += NOR + " 仙界目前正在派發禮物，隨機派送給在線玩家，剩餘的禮物清單如下：\n" + NOR;
        }
        msg += query_giftlists() + "\n" + NOR;
    } else {
        msg += NOR + "(目前仙界沒有派發禮物的計劃。)\n" + NOR;
    }
    if (wiz_level(me) > 5) msg += HIK + "(本行僅巫師可見) - 指令：<tname|tlevel|trequire|tstart  qqaddkey|qqstart \n gf3add(qq,id)|qqstart|gf3start|gf3stop>\n" + NOR;
    return msg;
}

int query_autoload() { return 0; }
int clean_up(int inherited) { return 1; }

void create() {
    set_name(NOR BWHT YEL "幸運" CYN "之" GRN "樹" NOR, ({ "lucky tree" }));
    set_weight(100000000000);
    set("longx", NOR HIW "這是紅蓮種植的白玉古樹，枝頭匍匐著" + chinese_number(SEND_NUM) + "只" NOR YEL "三足金蟾" HIW
        "仰望星辰。\n金蟾的大嘴不停吞吐溫養著海量的珠寶財物，琳琅滿目讓人眼花繚亂。\n" NOR);
    set("unit", "棵");
    set("value", 1);
    set("no_uget", 1);
    set("no_drop", 1);
    set("no_give", 1);
    set("no_sell", 1);
    set("no_get", 1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_put", 1);
    set("no_store", 1);

    set("unique", 1);
    set("no_pawn", 1);

    set("gift_level", 4);   //默認發最低級禮物
    set("gift_delay", 600);     //默認10分鐘噴發一次，每小時6次，避免太刷屏
    set("gift_require_level", R_LEVEL);
    set("gift_require_onlineday", R_ONLINEDAY);

    set_heart_beat(60);
    setup();
}

void post_channel(string arg) {
    //DEBUG_CHANNEL(arg);
    CHANNEL_D->channel_broadcast("news", arg);
}

int do_tname(string arg) {
    if (!arg) return notify_fail(NOR "你想把樹重新命名為什麼？比如<tname 聖誕>\n" NOR);
    set_name(NOR + BWHT + YEL + arg + CYN + "之" + GRN + "樹" + NOR, ({ "lucky tree" }));
    write("ok\n");
    return 1;
}

int do_tlevel(string arg) {
    int lv;
    if(!arg || sscanf(arg, "%d", lv) != 1 ) lv = 4;
    if (lv < 1) lv = 1;
    if (lv > 4) lv = 4;
    set("gift_level", lv);
    if (lv == 1)            write("你設置了最高的禮物等級。\n");
    else if (lv == 2)       write("你設置了中上的禮物等級。\n");
    else if (lv == 3)       write("你設置了普通的禮物等級。\n");
    else                            write("你設置了最低的禮物等級。\n");
    return 1;
}

int do_tdelay(string arg) {
    int idelay;
    if(!arg || sscanf(arg, "%d", idelay) != 1 ) idelay = 600;
    if (idelay < 60) idelay = 60;
    if (idelay > 3600) idelay = 3600;
    set("gift_delay", idelay);
    write("你設置了每隔" + (string)(idelay / 60) + "分鐘噴發一次禮物。\n");
    return 1;
}

int do_tstart(string arg) {
    int idelay;
    if(!arg || sscanf(arg, "%d", idelay) != 1 )
        return notify_fail(NOR "你想多久以後開始發送禮物？< 指令格式：tstart 小時數(最少1) >\n" NOR);
    if (idelay < 1) idelay = 1;
    set("start_at_time", time() + idelay * 3600 + 61);
    set_giftlists();
    write("你設置了在" + (string)(idelay) + "小時後開始發送禮物 (look lucky tree可以獲得信息，想取消發送用tcancel指令)。\n");
    return 1;
}

int do_tcancel() {
    object me = this_player();
    delete("start_at_time");
    post_channel(NOR + HIW + query("name", me) + NOR + HIW + "取消" + query("name") + NOR + HIW + "發送禮物的計劃了。\n" + NOR );
    write("你取消了禮物的發送。\n");
    return 1;
}

int do_trequire(string arg) {
    int ilv, iday;
    if(!arg || sscanf(arg, "%d %d", iday, ilv) != 2 )
        return notify_fail(NOR "你想限制在線多少天，等級至少達到多少級的玩家才能獲得？< 指令格式：do_trequire 天數 等級數 >\n" NOR);
    if (ilv < 0) ilv = 0;
    if (iday < 0) iday = 0;
    set("gift_require_level", ilv);
    set("gift_require_onlineday", iday);
    write("ok。\n");
    return 1;
}

int do_qqstart(string arg) {
    object ob;
    if(!arg)
        return notify_fail(NOR "你想通過QQ群發什麼禮物？arg參數為可以clone的物品文件。\n" NOR);
    ob = new(arg);
    if (!ob || !objectp(ob))
        return notify_fail(NOR "arg參數為可以clone的物品文件。\n" NOR);
    set("qqgroup/gift", arg);
    set("qqgroup/giftname", NOR + query("name", ob) + NOR);
    write(NOR + "設置禮品為" + query("name", ob) + NOR + "ok。\n");
    return 1;
}

int do_qqaddkey(string arg) {
    string *sa;

    if(!arg)
        return notify_fail(NOR "你想添加什麼禮物序號？arg參數為字串或字串數組，數組中間用,隔開。\n" NOR);

    sa = explode(arg, "," );
    set("qqgroup/keys", sa + (query("qqgroup/keys") ? query("qqgroup/keys") : ({})) );
    //write( NOR CYN + implode(query("qqgroup/keys"), ",") + "\n" + NOR);
    write("ok。\n");
    return 1;
}

void remove_qqkey(string arg) {
    if (!query("qqgroup/keys")) return;
    set("qqgroup/keys", query("qqgroup/keys") - ({ arg }) );
}

int do_input(string arg) {
    int i;
    object me = this_player();
    if(me->is_busy() )
    {
        write(NOR BUSY_MESSAGE NOR);
        return 1;
    }
    if (!query("qqgroup/gift")) {
        write(NOR "目前沒有派發禮物。\n" NOR);
        return 1;
    }
    if(!arg || sscanf(arg, "%d", i) != 1)
        return 0;
    if (query("gf3_flag")) {
        if (!gf3query(arg)) {
            me->start_busy(15);
            return 1;
        }
    } else {
        if (!query("qqgroup/keys"))
            return 0;
        if (!sizeof(query("qqgroup/keys")))
            return 0;
        if (member_array(arg, query("qqgroup/keys")) == -1)
        {
            write(NOR "你在瞎搞什麼？\n" NOR);
            me->start_busy(15);
            return 1;
        }
        remove_qqkey(arg);
    }
    CHANNEL_D->channel_broadcast("chat", (NOR + HIC + query("name", me) + NOR + HIC + "(" + query("id", me) + NOR + HIC +
        ((query("gf3_flag")) ? ("_QQ" + query_temp("gf3_qq", me)) : "") + ")從幸運樹獲得了" + query("qqgroup/giftname") + NOR + HIC + "。\n" + NOR) );
    write(NOR "你獲得了" + query("qqgroup/giftname") + "。\n" NOR);
    new(query("qqgroup/gift"))->move(me, 1);
    log_file("static/luckytreeqq", sprintf("%s " + query("qqgroup/giftname") + ", 獲得者( %s )\n", TIME_D->replace_ctime(time()), query("id", me)));
    return 1;
}

//gift3
mapping dt = ([]);

int do_save(mapping val) {
    string rvl;
    string s;
    dt = ([]);

    if (file_size(__DIR__"luckytreedata.o")>0) {
        s = read_file(__DIR__"luckytreedata.o");
        dt = restore_variable(s);
    }
    dt = val;
    rvl = save_variable(dt);
    return write_file(__DIR__"luckytreedata.o", rvl, 1);
}

mixed do_load() {
    string s;
    dt = ([]);

    if (file_size(__DIR__"luckytreedata.o")>0) {
        s = read_file(__DIR__"luckytreedata.o");
        dt = restore_variable(s);
    }
    return dt;
}

int do_gf3add(string arg) {
    string qq, idname;
    if(!arg || sscanf(arg, "%s %s", qq, idname) != 2) {
        return notify_fail(NOR "你想怎麼註冊？< 指令格式：gf3add qq號(沒有qq號此處也填寫玩家id) id>\n" NOR);
    }
    dt[qq] = (["id": idname, "lasttime": 1]);
    //dt["gf3"] += ([qq : (["id" : idname, "lasttime" : 1]) ]);
    do_save(dt);
    write("ok\n");
    return 1;
}

int gf3query2(string qq) {
    dt = do_load();
    if (!dt || !sizeof(dt)) return 0;
    if (member_array(qq, keys(dt)) == -1) return 0;
    return dt[qq]["lasttime"];
}

int gf3query(string qq) {
    int lasttime;
    object me = this_player();

    if (!query("gf3_flag")) {
        write(NOR "目前沒有派發禮物。\n" NOR);
        return 0;
    }
    lasttime = gf3query2(qq);
    if (!lasttime) {
        write(NOR "這個QQ帳號沒有登記過。\n" NOR);
        return 0;
    }
    if (dt[qq]["id"] != query("id", me)) {
        write(NOR "這個QQ不該由你來領取禮物。\n" NOR);
        return 0;
    }
    if (lasttime == (time() / 86400)) {
        write(NOR "今天已經領取過禮物了。\n" NOR);
        return 0;
    }
    dt[qq] = (["id": query("id", me), "lasttime": (time() / 86400)]);
    do_save(dt);
    set_temp("gf3_qq", qq, me);
    write(NOR "領取禮物成功。\n" NOR);
    return 1;
}

int do_gf3start() {
    dt = do_load();
    set("gf3_flag", 1);
    write(query("gf3_flag") + "\n");
    return 1;
}

int do_gf3stop() {
    set("gf3_flag", 0);
    write(query("gf3_flag") + "\n");
    return 1;
}

void init() {
    object me = this_player();
    add_action("do_input", "input");
    if (query("id", me)==query("grant_id"))
        add_action("do_gf3add", "gf3add");
    if (!playerp(me) || wiz_level(me) < 6) return;
    add_action("do_tname", "tname");
    add_action("do_tlevel", "tlevel");
    add_action("do_trequire", "trequire");
    add_action("do_tdelay", "tdelay");
    add_action("do_tstart", "tstart");
    add_action("do_tcancel", "tcancel");
    add_action("do_qqaddkey", "qqaddkey");
    add_action("do_qqstart", "qqstart");
    add_action("do_gf3add", "gf3add");
    add_action("do_gf3start", "gf3start");
    add_action("do_gf3stop", "gf3stop");
}

void heart_beat() {
    object where = environment();
    int fstart, ct, start_time = query("start_at_time");
    int yjtime;

    if (!start_time) return;
    if (!where || !objectp(where) || !where->is_room()) return;
    fstart = start_time > time();
    if (fstart) {
        yjtime = query("send_items_count") / SEND_NUM * (query("gift_delay") + 1) / 3600;
        if (yjtime<1) yjtime = 1;
        ct = start_time - time();
        ct /= 60;
        if (ct >= 60 && (ct % 60) == 0) {
            ct /= 60;
            //可惡的小白們，自己不開news頻道，還只有我去chat頻道刷
            CHANNEL_D->channel_broadcast("chat", (NOR + HIC + query("name") + NOR + HIC + "(鞦韆園)將於" + chinese_number(ct) + NOR + HIC +
                "小時後，開始持續" + chinese_number(yjtime) + "小時派禮(詳見新聞頻道)，給在線超" + chinese_number(query("gift_require_onlineday")) + "天、等級超" + chinese_number(query("gift_require_level")) + "級的玩家。\n" + NOR ));
        } else if (ct != 0) {
            if (((ct<31) && ((ct % 5)==0)) || (ct<5) ) {
                post_channel(NOR + HIG + query("name") + NOR + HIG + "(鞦韆園)將於" + chinese_number(ct) + NOR + HIG +
                    "分鐘後，開始持續" + chinese_number(yjtime) + "小時派禮，給在線超" + chinese_number(query("gift_require_onlineday")) + "天、等級超" + chinese_number(query("gift_require_level")) + "級的玩家。\n" + NOR );
            }
        }
        return;
    }
    if (query("send_at_time") <= time() ) {
        set("send_at_time", time() + query("gift_delay"));
        send_giftlists();
    }
}

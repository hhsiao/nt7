// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

#define ENCNUM 16
#define ENCRND 4
#define DELAY_T 1000

int clean_up() { return 1;}

void create() {
    set("short", "珍寶閣");
    set("long",
        "這就是珍寶閣的所在，一棟九色的樓層拔地而起，赤橙黃綠青藍紫為前\n"
        "七層，然後為黑色一層，白色的頂層為最高，上面高懸一顆碧水珠，光彩奪\n"
        "目，人們一到珍寶閣十丈之內，立刻如沐春風，清爽無比，在珍寶閣各路珍\n"
        "稀的寶物讓人眼花繚亂，價值也是動人心魄。\n"
    );
    //set("outdoors", "yangzhou");
    set("exits",([ /* sizeof() == 1 */
        "south": __DIR__"zoulang21"
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);

    set("encounter/SN", random(ENCRND) + 1);
    set("encounter/amount", ENCNUM / 4);
    set("encounter/ntime", time() + DELAY_T + random(DELAY_T / 2));
    setup();
}

void init_encounter(object me)  //陣圖進入調用
{
    if (query("dongtian/encounter/SN1", me) && query("dongtian/encounter/SN1", me) < (ENCRND + 1)) return;
    set("dongtian/encounter/SN1", random(ENCRND) + 1, me);
}

void add_encounter()    //陣圖定時調用
{
    if (query("encounter/ntime") > time() || query("encounter/amount") >= ENCNUM) return;
    if (query("hold_time", get_object(__DIR__"guangchang.c")) < 2) return;  //是npc的洞天
    set("encounter/ntime", time() + DELAY_T + random(DELAY_T / 2));
    addn("encounter/amount", 1);
    if (query("encounter/amount") >= ENCNUM) {
        CHANNEL_D->channel_broadcast("dt", NOR + HIW + "遠望" + NOR + HIC + __DIR__"guangchang.c"->load_name() + NOR + HIW + "洞天的" + query("short") + "方向，寶光充盈氣衝雲霄。\n" + NOR);
    }
}

void init() {
    int rnd;
    object ob;
    //      object room;
    string obname;
    object me = this_player();
    object gcroom = get_object(__DIR__"guangchang.c");
    int halfamount;
    string *giftobs = ({});

    if (!query("dongtian/encounter/SN1", me))
        init_encounter(me);

    if (playerp(me) &&
        ((query_temp("dongtian/houshan/hold_time", me)==query("hold_time", gcroom) && !gcroom->owner_level(me)) || (query("dongtian/encounter/SN1", me) && query("dongtian/encounter/SN1", me)==query("encounter/SN")) )
        && query("encounter/amount")) {
        halfamount = query("encounter/amount") / 2;
        while (query("encounter/amount")>halfamount) {
            set("encounter/ntime", time() + DELAY_T + random(DELAY_T / 2));
            addn("encounter/amount", -1);
            set("encounter/SN", random(ENCRND) + 1);
            delete("dongtian/encounter/SN1", me);
            init_encounter(me);

            //獎勵
            rnd = random(560);
            if (rnd < 1)
                ob = new("/u/redl/obj/fanghuamu");
            else if (rnd < 5)
                ob = EQUIPMENT_D->create_dynamic("", 60, 600);
            else if (rnd < 8)
                ob = new("/clone/tessera/rune" + to_string(31 + random(3)));
            else if (rnd < 35)
                ob = new("/clone/tessera/rune" + to_string(26 + random(5)));
            else if (rnd < 99)
                ob = new("/clone/tessera/rune" + to_string(21 + random(5)));
            else if (rnd < 199)
                ob = EQUIPMENT_D->create_dynamic("", 60, 500);
            else if (rnd < 250)
                ob = new("/d/kaifeng/linggt/npc/obj/tlcrystal");
            else if (rnd < 260)
                ob = new("/clone/tongren/tongren2");
            else if (rnd < 270)
                ob = new("/clone/tongren/tongren1");
            else
                ob = EQUIPMENT_D->create_dynamic("", 60, 400);

            if (!ob->move(this_object()))
            {
                destruct(ob);
            }
            else
            {
                me->start_busy(5 + random(6));  //等待被主人抓賊
                set("who_get/id", query("id", me), ob);
                set("who_get/time", time() + 90, ob);
                obname = query("colorname", ob);
                if (undefinedp(obname) || !obname)
                    obname = query("name", ob);
                message_vision(append_color(
                    NOR + CYN + (random(2) ? "哐啷" : "噹地") + (random(2) ? "~ " : "，") + NOR + CYN + "$N" + (random(2) ? "踩" : "踢") + (random(2) ? "到" : "住") + obname + NOR + CYN + (random(2) ? ".." : "...") + "\n" NOR,
                    CYN), me);
                //if (rnd < 99)
                giftobs += ({ obname });
                /*
                 * //if (rnd < 270) {//通知主人方
                 * if (objectp(room = get_object(__DIR__"houdian"))) {
                 * tell_room(room, NOR + HIG + "魔像：" + query("name", me) + NOR + HIG + "在本洞天發現了" + obname + NOR + HIG + "。\n" + NOR);
                 * }
                 * room = get_object(__DIR__"dadian");
                 * if (objectp(room)) {
                 * tell_room(room, NOR + HIG + "魔像：" + query("name", me) + NOR + HIG + "在本洞天發現了" + obname + NOR + HIG + "。\n" + NOR);
                 * }
                 * //}*/
            }
        }
        if(giftobs && sizeof(giftobs))
            CHANNEL_D->channel_broadcast("dt", sort_msg(NOR + HIW + "傳說有人在" + NOR + HIC + __DIR__"guangchang.c"->load_name() + NOR + HIW + "洞天的" + query("short") + "發現了" + implode(giftobs, NOR + HIW + "、" + NOR + HIW) + NOR + HIW + "。\n" + NOR, 64));
    }

    ::init();
}

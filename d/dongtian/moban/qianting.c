// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

string look_bei(object me) {
    string *owns;
    if (me->is_busy()) {
        return  NOR "你還是忙完手頭上的事情再看吧。\n" NOR;
    }
    me->start_busy(3);
    owns = __DIR__"data.c"->do_load("owners");
    if (!undefinedp(owns) && arrayp(owns) && sizeof(owns)>0) {
        return CYN "石碑上刻著一行名字："+implode(owns, "、") + "。\n"+NOR + "( 記於 - "+ctime(__DIR__"data.c"->do_load("hold_time")) + " )\n\n" NOR;
    }
    return CYN "石碑上空空如也。\n\n" NOR;
}

void create() {
    set("short", "前庭");
    set("long",
        "廣場盡頭，一座石橋，無座無墩，橫空而起，一頭搭在廣場，徑直斜伸\n"
        "向上，入白雲深處，如姣龍躍天，氣勢孤傲。陽光照下，整座橋散發七彩顏\n"
        "色，如天際彩虹落凡間，絢麗繽紛，美輪美奐。踏上石橋，兩側流水潺潺，\n"
        "清澈無比，走過石橋，竟是出了雲海，眼前驀然一亮，只見長空如洗，藍的\n"
        "如ＰＳ過一樣。四面天空，廣無邊際。下有云海茫茫，一眼望去，心胸頓時\n"
        "為之一寬。這便是前庭所在，庭中豎著一個石碑("CYN"bei"NOR")。\n"
        NOR
    );
    set("outdoors", "dongtian");
    set("exits",([ /* sizeof() == 1 */
        "north": __DIR__"dadian",
        "south": __DIR__"guangchang",
        "east": __DIR__"zoulang11",
        "west": __DIR__"zoulang21"
        ]));
    set("item_desc", ([
        "bei": (: look_bei :)
        ]) );

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 20);

    setup();
}

void init() {
    object me = this_player();
    if (userp(me)) me->command("maphere");
    ::init();
}

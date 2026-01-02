// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "傳送陣");
    set("long",
        "這裡是山巔的一片空地。空地正中，赫然是一座巨大的圓形法陣，底部\n"
        "懸空，十三根白玉石所做的高達三丈的巨大石柱支撐起整座法陣。其中法陣\n"
        "邊緣共有十二根白玉石柱，每一根都有二人合抱之粗，而在法陣中間，最粗\n"
        "大的一根白玉石柱看上去至少需要六七個人才能合抱過來，高入雲霄。石柱\n"
        "不時亮起，法陣之中隱隱有人影顯現。\n"
    );
    set("outdoors", "dongtian");
    set("exits", ([ /* sizeof() == 1 */
        "east": __DIR__"houshan",
        "enter": "/u/redl/teleport/teleport"
        ]));

    set("no_fight", 1);     //這裡絕對不能戰鬥，不然會回到水牢
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    //set("max_carry_user" ,20);

    setup();
}

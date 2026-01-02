// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "走廊");
    set("long",
        "這條長廊優雅精緻，盤龍小柱頂著一個個的蓋子，連接著各個去處，一\n"
        "個個的蓋子上面都是一幅精美的畫卷，從盤古開天，到封神之戰，讓人走在\n"
        "這長廊之上，也能感受上古之戰的地裂天崩。\n"
    );
    set("outdoors", "dongtian");
    set("exits", ([ /* sizeof() == 1 */
        "south": __DIR__"zoulang22",
        "north": __DIR__"zoulang24"
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 20);

    setup();
}

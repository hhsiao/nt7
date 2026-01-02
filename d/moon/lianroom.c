// ken 1999.12.9
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "練功場");
    set("long", @LONG
 這個練武場比起其他的要大了幾倍，細紗鋪成的場地在
陽光下熠熠生光。在場地旁邊放著幾個兵器架，兵器架上
插滿了各式各樣的武器。
LONG	);
    set("exits", ([
        "westup": __DIR__"fgaden"
        ]));
    set("objects", ([
        __DIR__"npc/guards1" : 4,
        __DIR__"obj/jia" : 1
        ]) );
    set("coor/x",-20);
    set("coor/y", 1090);
    set("coor/z", 30);
    setup();
}

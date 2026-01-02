// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "陽關大道");
    set("long", @LONG
一條筆直的大路，向著西方蔓延著，看來是通向遙遠的邊疆的。
LONG	);
    set("exits", ([
        "north": __DIR__"zz7",
        "west": __DIR__"zz2",
        "east": "/d/xj/heimiao"
        ]));
    set("coor/x",-10);
    set("coor/y", 1000);
    set("coor/z", 0);
    setup();
}

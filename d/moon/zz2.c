// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "陽關大道");
    set("long", @LONG
一條筆直的大路，向著西方蔓延著，看來是通向遙遠的邊疆的。
可惜前方好象還在修路，行人紛紛折返。
LONG	);
    set("exits", ([
        "west": "/d/moon/zz1",
        "east": "/d/xj/heimiao"
        ]));
    set("coor/x",-20);
    set("coor/y", 1000);
    set("coor/z", 0);
    setup();
}

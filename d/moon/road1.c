// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "山路");
    set("long", @LONG
一條彎彎曲曲的小路，向山上盤旋延深著。
LONG	);
    set("exits", ([
        "up": __DIR__"road2",
        "southdown": __DIR__"caodi"
        ]));
    set("coor/x",-30);
    set("coor/y", 1060);
    set("coor/z", 10);
    setup();
}

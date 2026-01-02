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
        "northup": __DIR__"door",
        "down": __DIR__"road2"
        ]));
    set("coor/x",-30);
    set("coor/y", 1060);
    set("coor/z", 30);
    setup();
}

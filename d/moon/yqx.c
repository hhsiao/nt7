// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "倚秋軒");
    set("long", @LONG
這裡是丁鵬平時最愛駐足的地方，因為青青在的時候經常會
斜倚小窗，靜靜地看著遠處的紅楓，獨坐很久很久.......
LONG	);
    set("exits", ([
        "westup": __DIR__"qfg",
        "southdown": __DIR__"egate"
        ]));
    set("objects", ([
        __DIR__"npc/guards2" : 2,
        __DIR__"npc/npc1" : 1
        ]) );
    set("coor/x",-20);
    set("coor/y", 1130);
    set("coor/z", 50);
    setup();
}

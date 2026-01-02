// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "一水天");
    set("long", @LONG
從這裡一眼就可以看到瀉玉泉淙淙的流水，微風拂過，隱約聽到
有如琴音的流水聲，會同這裡古樸的擺設和裝飾，令你彷彿置身
世外桃源，唯願獨自去體味那種恬靜與適意。
LONG	);
    set("exits", ([
        "eastup": __DIR__"qfg",
        "southdown": __DIR__"wgate"
        ]));
    set("objects", ([
        __DIR__"npc/guards2" : 2,
        __DIR__"npc/npc2" : 1
        ]) );
    set("coor/x",-40);
    set("coor/y", 1130);
    set("coor/z", 50);
    setup();
}

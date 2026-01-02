// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "清風閣");
    set("long", @LONG
這裡是圓月山莊的第二大建築。古槐覆陰之下，紅樓掩映，
上面彩紗宮燈，綴成了“清風閣”三字。四周的石欄，掛滿許多
水晶玻璃的各色風燈，點得如銀花雪浪。
LONG	);
    set("exits", ([
        "northup": __DIR__"yyl",
        "southdown": __DIR__"froom",
        "eastdown": __DIR__"yqx",
        "westdown": __DIR__"yst"
        ]));
    set("objects", ([
        __DIR__"npc/guards2" : 2,
        __DIR__"obj/deng" : 1
        ]) );
    set("valid_startroom", 1);
    set("coor/x",-30);
    set("coor/y", 1130);
    set("coor/z", 60);
    setup();
}

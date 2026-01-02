// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "山莊大門");
    set("long", @LONG
這兒就是名震江湖的圓月山莊，山莊的大門是一座高大的飛簷建築，
其氣勢恢弘非任何門派可以比擬。左右兩隻石獅遙相呼應，中間上方
懸掛著一方金匾;
[33m

                       圓 月 山 莊

[37m
LONG	);
    set("exits", ([
        "north": __DIR__"bi",
        "southdown": __DIR__"road3"
        ]));
    set("objects", ([
        __DIR__"npc/guards2" : 2
        ]) );
    set("coor/x",-30);
    set("coor/y", 1070);
    set("coor/z", 40);
    setup();
}

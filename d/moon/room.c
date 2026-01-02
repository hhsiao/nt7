// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "大廳");
    set("long", @LONG
這是一間金碧輝煌的大廳，漢白玉為階，兩旁一排石交椅，
石階上方擺放著一張巨案。看來是此處是山莊集會之所。
LONG	);
    set("exits", ([
        "north": __DIR__"froom",
        "south": __DIR__"gaden",
        "east": __DIR__"eroom1",
        "west": __DIR__"wroom1"
        ]));
    set("objects", ([
        __DIR__"npc/guards2" : 2,
        __DIR__"npc/npc4" : 1
        ]) );
    set("coor/x",-30);
    set("coor/y", 1110);
    set("coor/z", 40);
    setup();
}

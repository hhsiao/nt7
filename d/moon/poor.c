// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "瀉玉泉");
    set("long", @LONG
揚花飄落，小荷初生。鶯啼紅樹，蝶舞其間。仔細觀看水池中建
一假山，上書瀉玉二字，一眼活泉從假山上流過，一直向西延伸。
泉水流過山石，丁冬聲竟似琴音。陽光雖烈，此處卻清幽異常，
可見其建築的獨具匠心。
LONG	);
    set("exits", ([
        "east": __DIR__"froom1"
        ]));
    set("objects", ([
        __DIR__"obj/poor" : 1
        ]) );
    set("coor/x",-40);
    set("coor/y", 1150);
    set("coor/z", 40);
    setup();
}

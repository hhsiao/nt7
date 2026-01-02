// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create() {
    set("short", "芳草地");
    set("long", @LONG
這裡到處是各式各樣的奇花異草。向左看去，則有一個小湖，
幽風襲面，清香暗湧。北面則是陡峭的山崖，剛才所見的燈
光似乎就來自這座山上。
LONG
    );
    set("exits", ([
        "east": __DIR__"caodi"
        ]));
    set("objects", ([
        __DIR__"obj/grass" : 1
        ]) );
    set("coor/x",-40);
    set("coor/y", 1050);
    set("coor/z", 0);
    setup();
}

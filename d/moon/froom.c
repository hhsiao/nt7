// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "前花園");
    set("long", @LONG
但見綠樹濃陰稠密，樓臺倒影於池塘，微風吹動，水波盪漾；
回首園中，薔薇滿架，香氣襲人，馨馥滿庭。透過婆娑樹影，
往北隱隱看到清風閣的一角飛簷。
LONG	);
    set("exits", ([
        "northup": __DIR__"qfg",
        "south": __DIR__"room"
        ]));
    set("coor/x",-30);
    set("coor/y", 1120);
    set("coor/z", 40);
    setup();
}

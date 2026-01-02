// ken 1999.12.9

#include <room.h>
inherit ROOM;
void create() {
    set("short", "月影樓");
    set("long", @LONG
此處兩邊飛樓插空，雕欄繡檻，綠窗油壁。
四面香風，穿窗而入，令人沉醉。
LONG	);
    set("exits", ([
        "up": __DIR__"yyl2",
        "down": __DIR__"yyl"
        ]));
    set("coor/x",-30);
    set("coor/y", 1140);
    set("coor/z", 80);
    setup();
}

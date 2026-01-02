// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create() {
    set("short", "右偏廳");
    set("long", @LONG
 這裡是專門招待來訪貴賓用膳的地方，廳中央擺放著
一張黑玉打磨而成的八仙桌，上面放著幾隻玉盞，能坐
在這裡的，都是武林中成名的人物。
LONG	);
    set("exits", ([
        "west": __DIR__"room",
        "north": __DIR__"egate"
        ]));
    set("coor/x",-20);
    set("coor/y", 1110);
    set("coor/z", 40);
    setup();
}

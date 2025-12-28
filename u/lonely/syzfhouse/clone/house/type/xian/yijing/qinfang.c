// xixiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "琴房");
    set("long", @LONG
這裡是主人閒來彈琴之處，房內陳設甚為簡單，一角置著琴榻琴凳，
另一角放著香爐。
LONG);

    set("exits",
    ([
        "east"  : __DIR__"houting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

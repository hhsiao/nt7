// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "客廳");
    set("long", @LONG
這裡是幫內招待八方來客的地方。
LONG);

    set("exits",
    ([
        "south" : __DIR__"wuchang",
        "north" : __DIR__"wofang",
        "west"  : __DIR__"xixiang",
        "east"  : __DIR__"dongxiang",
    ]));

    set("objects", __DIR__"board");

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");
    set("resource/water", "茶水");
    setup();
    restore();
}

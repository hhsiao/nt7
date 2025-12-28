// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "客廳");
    set("long", @LONG
一間小小的客廳。
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
        "north" : __DIR__"wofang",
        "west"  : __DIR__"xixiang",
        "east"  : __DIR__"dongxiang",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");
    set("resource/water", "茶水");

    setup();
    restore();
}

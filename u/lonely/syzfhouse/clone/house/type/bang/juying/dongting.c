// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "講武堂");
    set("long", @LONG
這裡是幫內人士探討武功的地方。
LONG);

    set("exits",
    ([
        "west"  : __DIR__"xiaoting",
        "north" : __DIR__"dongxiang",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

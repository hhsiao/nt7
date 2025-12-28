// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "臥房");
    set("long", @LONG
一間小小的臥房。
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

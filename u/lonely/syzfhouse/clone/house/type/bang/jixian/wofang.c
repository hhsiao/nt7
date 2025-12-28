// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "臥房");
    set("long", @LONG
這裡是幫內人士休息的臥房。
LONG);

    set("exits",
    ([
        "north" : __DIR__"houyuan",
        "south" : __DIR__"xiaoting",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

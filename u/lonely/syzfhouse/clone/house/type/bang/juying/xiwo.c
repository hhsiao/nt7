// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "臥房");
    set("long", @LONG
這是偏處西側的一間臥房，是幫中弟子休息之處。
LONG);

    set("exits",
    ([
        "east"  : __DIR__"wofang",
        "south" : __DIR__"xixiang",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

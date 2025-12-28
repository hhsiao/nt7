// xixiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "議事廳");
    set("long", @LONG
這是幫主和幫內重要人物商量大事之處，擺著不少桌椅。
LONG);

    set("exits",
    ([
        "east" : __DIR__"xiaoting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

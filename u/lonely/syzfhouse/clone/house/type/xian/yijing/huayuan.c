// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "花園");
    set("long", @LONG
這裡是位於中庭的花園，種植著許多產自五湖四海，名山大川的奇花
異草，美麗非常。
LONG);

    set("exits",
    ([
        "north" : __DIR__"houting",
        "south" : __DIR__"qianting",
    ]));

    set("outdoors", "OUTDOORS");
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

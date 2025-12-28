// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "西廂");
    set("long", @LONG
這是一間位於西側的廂房，東面通往正廳。
LONG);

    set("exits",
    ([
        "east"  : __DIR__"qianting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

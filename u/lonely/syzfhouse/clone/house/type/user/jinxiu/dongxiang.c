// dongxiang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "東廂");
    set("long", @LONG
一間位於東側的廂房。
LONG);

    set("exits",
    ([
        "west" : __DIR__"xiaoting",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

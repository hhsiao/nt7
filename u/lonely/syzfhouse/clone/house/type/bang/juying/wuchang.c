// xiaoyuan.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "練武場");
    set("long", @LONG
一片很大的廣場，是幫內弟子練武的地方。
LONG);

    set("exits",
    ([
        "south" : __DIR__"xiaoyuan",
        "north" : __DIR__"xiaoting",
    ]));

    set("owner_name", "某人");
    set("owner", "OWNER");
    set("outdoors", "OUTDOORS");

    setup();
    restore();
}

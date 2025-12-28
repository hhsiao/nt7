// wofang.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "臥房");
    set("long", @LONG
這是主人的臥室，收拾得井井有條。推開窗戶可以看到下面的花園，
隱隱可嗅到陣陣花香，非常愜意。
LONG);

    set("exits",
    ([
        "down"  : __DIR__"houting",
    ]));

    set("sleep_room", 1);
    set("no_fight", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");

    setup();
    restore();
}

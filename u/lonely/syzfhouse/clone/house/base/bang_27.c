
inherit "/inherit/room/house_base";

void create()
{
    set("short", "山坡");
    set("long", @LONG
這裡是少室山之陽的一座山坡，坡上長滿了豔紅色的不知名的野
花，採蜜的蜂蝶們簇成一團團忙碌著。坡上依山而建一座恢宏大院，
似乎是江湖中哪個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east"  : "/d/shaolin/xiaojing1",
    ]));

    set("outdoors", "shaolin");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}


inherit "/inherit/room/house_base";

void create()
{
    set("short", "龍泉山麓");
    set("long", @LONG
這裡是龍泉山路，再往北走可以通向山中的黑龍潭。往南去則是
有名的石林迷宮。路旁岔出一條不是很長的小徑，盡頭有好大的一片
宅院，看上去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "south" : "/d/yunnan/hl-road1",
        "north" : "/d/yunnan/hl-tan",
    ]));

    set("outdoors", "yunnan");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}

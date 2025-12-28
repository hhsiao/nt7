// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "後廳");
    set("long", @LONG
這裡是位於花園後側的一間內廳，是主人招待知交好友的地方，陳設
樸素雅緻，打掃得纖塵不染。東面是書齋，西側是琴房。樓上則是主人的
臥室。
LONG);

    set("exits",
    ([
        "west"  : __DIR__"qinfang",
        "east"  : __DIR__"shuzhai",
        "up"    : __DIR__"wofang",
        "north" : __DIR__"houyuan",
        "south" : __DIR__"huayuan",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");
    set("resource/water", "茶水");
    setup();
    restore();
}

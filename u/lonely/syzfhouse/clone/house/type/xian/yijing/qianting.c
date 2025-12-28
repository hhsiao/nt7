// ting.c

inherit "/inherit/room/house_room";

void create()
{
    set("short", "前廳");
    set("long", @LONG
這裡是主人迎接八方來客的地方。大凡客人來拜見主人，少不得在這
裡寒暄敘話，了盡仰慕之情。東西兩側各是一間廂房。
LONG);

    set("exits",
    ([
        "east"  : __DIR__"dongxiang",
        "west"  : __DIR__"xixiang",
        "south" : __DIR__"qianyuan",
        "north" : __DIR__"huayuan",
    ]));

    set("no_learn", 1);
    set("owner", "OWNER");
    set("owner_name", "某人");
    set("resource/water", "茶水");
    setup();
    restore();
}

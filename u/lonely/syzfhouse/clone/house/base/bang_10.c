
inherit "/inherit/room/house_base";

void create()
{
    set("short", "侯監林內");
    set("long", @LONG
一片北方曠野中常見的樹林，樹幹高大挺直，枝葉稀疏，林間有
條小路蜿蜒穿越，通向遠處。一片宅院掩藏在樹林之內，看上去似乎
是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "east" : "/d/houjianji/shulin2",
    ]));

    set("outdoors", "houjianji");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}

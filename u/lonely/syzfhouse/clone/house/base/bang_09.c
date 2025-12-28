
inherit "/inherit/room/house_base";

void create()
{
    set("short", "滄州鎮東");
    set("long", @LONG
此處位於滄州鎮外不遠，沿著中原驛道向西行走，便可進入滄州
鎮。道旁楊樹林齊齊地立著，襯著其間氣派不凡的一大片宅院，看上
去似乎是某個幫會的駐地所在。
LONG);

    set("exits",
    ([
        "west" : "/d/ruzhou/cang-dong",
    ]));

    set("outdoors", "ruzhou");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}

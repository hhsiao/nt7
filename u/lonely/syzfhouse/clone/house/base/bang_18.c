
inherit "/inherit/room/house_base";

void create()
{
    set("short", "山間平臺");
    set("long", @LONG
這裡是山路以北的一片寬闊平臺，站在這裡可以俯看雙旗鎮的全
景。回過頭去，從這裡仰望白駝山，你就知道這座山名的由來了。峰
頂上有四時不化之積雪。平臺內側有一處恢宏宅院，好像是某個幫會
的駐地。
LONG);

    set("exits",
    ([
        "east"  : "/d/baituo/guangchang",
    ]));

    set("outdoors", "baituo");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}

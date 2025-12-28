
inherit "/inherit/room/house_base";

void create()
{
    set("short", "皇亭街己號");
    set("long", @LONG
這其實是一條比較寬的巷子，不過在江南就叫做大街了，路上的石
板都是新鋪的，既乾淨又平整。街兩邊都是民宅。
LONG);

    set("exits",
    ([
        "west"  : __DIR__"wuxi_05",
        "south" : __DIR__"wuxi_08",
        "north" : "/d/wuxi/huangting-xi2",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}


inherit "/inherit/room/house_base";

void create()
{
    set("short", "皇亭街壬號");
    set("long", @LONG
這其實是一條比較寬的巷子，不過在江南就叫做大街了，路上的石
板都是新鋪的，既乾淨又平整。向內有好大一片宅院，似乎是某個幫會
的駐地所在。
LONG);

    set("exits",
    ([
        "west"  : "/d/wuxi/huangting",
    ]));

    set("outdoors", "wuxi");
    set("max_build", 1);
    set("can_build", "bang");

    setup();
    restore();
}

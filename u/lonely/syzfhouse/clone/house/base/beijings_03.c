
inherit "/inherit/room/house_base";

void create()
{
    set("short", "永定街丙號");
    set("long", @LONG
永定東街位於京城之南，永定門內大街的東部。街道兩側劃出了
很多地塊，供來自各地的大富豪們在此修築豪宅美院。青石板鋪就的
道路頗為寬闊，掃洗得光可鑑人。路兩旁綠樹成蔭，掩映著其間的一
棟棟民宅，顯得安靜而優雅。
LONG);

    set("exits",
    ([
        "south" : "/d/beijing/yongding-dongjie2",
        "east"  : __DIR__"beijings_05",
        "west"  : __DIR__"beijings_01",
    ]));

    set("outdoors", "beijing-s");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}

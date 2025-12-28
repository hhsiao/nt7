
inherit "/inherit/room/house_base";

void create()
{
    set("short", "南山路甲號");
    set("long", @LONG
南山路位於西湖之畔，安靜幽美。路的兩側劃出了很多地塊，供
來自各地的大富豪們在此修築豪宅美院，因此南山路一帶也得了西湖
花園的美稱。道路並不是很寬，但處處充溢著西子湖獨特的風情，茂
盛的樹冠將烈日風雨完全地阻在了身外，走在這裡，唯一的心情就是
安靜甜美。
LONG);

    set("exits",
    ([
        "south" : "/d/linan/nanshan-lu1",
        "east"  : __DIR__"linan_03",
    ]));

    set("outdoors", "linan");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}

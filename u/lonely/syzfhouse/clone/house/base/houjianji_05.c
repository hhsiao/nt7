
inherit "/inherit/room/house_base";

void create()
{
    set("short", "侯監集戊號");
    set("long", @LONG
這裡位於侯監集南側一條行人稀少的幽長小巷之內，四周聚集著
很多的民宅，安靜而優雅。街道兩側劃分出了一個個的地塊，供來自
各地的英雄豪傑們在此修築豪宅美院。
LONG);

    set("exits",
    ([
        "east"  : __DIR__"houjianji_06",
        "north" : __DIR__"houjianji_01",
    ]));

    set("outdoors", "houjianji");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}

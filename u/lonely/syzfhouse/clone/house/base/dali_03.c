inherit "/inherit/room/house_base";

void create()
{
    set("short", "鎮南街丙號");
    set("long", @LONG
這是位於鎮南街畔的新闢住宅區，四周綠樹成蔭，藤蔓垂依，阻
隔了喧鬧的人聲，環境頗為優雅，靜謐而閒適。沿著街道劃出了不少
地塊，供來自各地的大富豪們在此修築豪宅美院。
LONG);

    set("exits",
    ([
        "west"  : __DIR__"dali_04",
        "south" : __DIR__"dali_01",
    ]));

    set("outdoors", "dali");
    set("max_build", 4);
    set("can_build", "user");

    setup();
    restore();
}
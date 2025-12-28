// Room: houyuan.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "後院");
	set("long", @LONG
後院乃劍湖宮清閒之所，一排茶花相間而開，青藤繞樹，兩三果子忽隱忽
現。靠牆放著一張長桌子，上面放了些水果，還有一隻大水壺。幾隻青瓷小碗
洗得乾乾淨淨。北面是一片松林，也是無量劍派的禁地。
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"jhg",
            "north" : __DIR__"songlin1",	    
        ]));
        set("outdoors", "大理");
	setup();
}
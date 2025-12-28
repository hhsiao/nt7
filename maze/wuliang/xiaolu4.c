// Room: xiaolu4.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "青石臺階");
	set("long", @LONG
這是由青石砌成的臺階，方方正正，看起來頗為考究，大青石一塊一塊直
鋪到大廳，臺階兩邊還做了欄杆。臺階四周長著一些野草，頭頂有一些不知名
的小鳥在跳來跳去。
LONG
	);
	set("exits", ([ 
	    "southdown" : __DIR__"xiaolu3",
	    "westup" : __DIR__"xiaolu5",
        ]));

        set("outdoors", "大理");

	setup();
}
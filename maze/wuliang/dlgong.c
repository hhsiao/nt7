// Room: dlgong.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "東練武廳");
	set("long", @LONG
這是無量山劍湖宮的練功房，兩邊有兩個兵器架，十八武器樣樣俱全，牆
角還散放著幾個練力的石錘和一些雜物，宮中弟子每天在此練功。 
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"jhg",
        ]));

	setup();
}
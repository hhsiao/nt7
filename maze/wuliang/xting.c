// Room: xting.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "西廳");
	set("long", @LONG
這裡是供來無量劍的客人休息之用，一應茶點具備，窗邊一溜平放著不少
錦凳，牆上掛著幾幅山水畫，幾縷陽光透過窗外的綠蔭中直射進來。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"wlj",	    
        ]));

	setup();
}
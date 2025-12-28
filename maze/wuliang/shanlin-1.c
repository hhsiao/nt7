// Modify By River 98/12 
inherit ROOM;

void create()
{
	set("short", "石道");
	set("long", @LONG
這裡亂石荊刺滿地，沒有一條象樣的路。你費力的走著，衣衫下襬被荊刺
撕成一片一片。西面是似乎來時候的森林。你喘了口氣，突然發覺一條人影向
東面逃去。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
            "east" : __DIR__"shanlin-2",
	    "west" : __DIR__"shanlu12",
	]));

	setup();
}

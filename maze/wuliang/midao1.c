// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
這裡是密道，黑乎乎的，你只能摸索著向前走，密道上面的就是你進來的
石屋子。你只能很費勁的鑽過一個個的密道。
LONG
	);        

	set("exits", ([
	    "southdown" : __DIR__"midao2",
	]));

	setup();
}
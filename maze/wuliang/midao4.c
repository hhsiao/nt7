// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
這裡是密道，黑乎乎的，什麼也看不真切，你只能摸索著向前走，很費勁
的鑽過一個個的密道。。
LONG
	); 
	set("exits", ([
	     "southdown" : __DIR__"midao5",
             "west" : __DIR__"midao3",
	]));

	setup();
}
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW"龍樹院"NOR);
	set("long", @LONG
你進入了一間小松木屋，木屋門上掛了一個牌匾，上邊寫著“龍樹院”，
你吃了一驚，想不到大名鼎鼎的天龍寺龍樹院竟然就是這間小屋。
LONG);
	set("indoors", "天龍寺");
	set("exits", ([             
		"out" : __DIR__"songlin-1",
	]));
	set("cant_hubiao", 1);
	set("objects",([
		__DIR__"npc/kurong" : 1,
	]));

	setup();
}

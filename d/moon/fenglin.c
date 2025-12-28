// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "楓林");
	set("long", @LONG
一踏入楓林，那濃得化不開的紅，和著楓葉特有的清香
撲面而來。剎那間，你的身心完全被這濃得化不開的紅
所陶醉了，駐足留連，久久不願離去......
LONG	);
	set("exits", ([ 
  "west" : __DIR__"froom1",
]));
         set("objects",([
			__DIR__"obj/feng" : 1,
                        __DIR__"npc/npc3" : 1,
       	]) );
	set("coor/x",-20);
	set("coor/y",1150);
	set("coor/z",40);
	setup();
}

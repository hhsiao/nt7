// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "東廂房");
	set("long", @LONG
這裡是供賓客休息的地方。所有的傢俱都被擦拭的
一塵不染。南牆上掛著一幅《松下舞劍圖》。
LONG	);
	set("exits", ([ 
  "west" : __DIR__"gaden",
]));
//          set("objects",([
//			__DIR__"npc/shinu" : 1,
//       	]) );
	set("coor/x",-20);
	set("coor/y",1100);
	set("coor/z",40);
	setup();
}

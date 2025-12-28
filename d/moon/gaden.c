// ken 1999.12.9

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "正院");
	set("long", @LONG
 這裡簡直就是一個小型的廣場，所有的地面都是用整齊的
青石鋪成，忙碌的家丁和侍女匆匆的走過，沒有人理會你，
看著通向四方的路，你簡直不知道該向哪裡走了。
LONG	);
	set("exits", ([ 
  "north" : __DIR__"room",
  "south" : __DIR__"fgaden",
  "east" : __DIR__"eroom",
  "west" : __DIR__"wroom",
]));
        set("coor/x",-30);
	set("coor/y",1100);
	set("coor/z",40);
        set("objects",([
       	]) );
	setup();
}

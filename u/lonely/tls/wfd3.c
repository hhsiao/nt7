// /u/cool/tls/wanfodong3.c
// cool 1998.2.13
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "萬佛洞內洞");
	set("long", @LONG
這裡是萬佛洞的內洞了，洞內顯得較昏暗異常，你看不清什麼東
西，洞內靜靜的，只聽見自己的腳步聲和心跳呼吸聲，隱隱有個人面
對著牆壁坐著。這裡沒有什麼明顯的出口。
LONG);
	set("exits", ([
	       "south" : __DIR__"wfd2",
        ]));
      
        create_door("south", "石門", "north", DOOR_CLOSED);
	setup();
}



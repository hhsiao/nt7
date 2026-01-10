// /u/cool/tls/wanfodong2.c
// cool 1998.2.13
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "萬佛洞");
	set("long", @LONG
陽光被外面的樹林遮住，這洞內顯得較昏暗，洞內滿是精美的佛
像，牆上繪著佛祖的一生事蹟的故事。走在洞裡，你看著牆上的壁畫，
感悟頗深。這裡沒有什麼明顯的出口。
LONG);
	set("exits", ([
	       "out" : __DIR__"wfd",
	       "north" : __DIR__"wfd3",

        ]));
        create_door("north", "石門", "south", DOOR_CLOSED);

	setup();
}

void init()
{
        add_action("do_linghui","領會");
        add_action("do_linghui","linghui");
}

int do_linghui(string arg)
{
	object me = this_player();
	message_vision("$N盤腿靜坐了下來，看著眼前的壁畫，良久，似有所悟。\n", me);
	me->set_busy(10);
//    me->set("shen",0);
	return 1;
}

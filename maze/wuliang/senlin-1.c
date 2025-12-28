// Modify By River 98/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "黑森林");
	set("long", @LONG
你信步而行，舉步踏到的盡是矮樹長草，這裡沒有路,每走一步，荊棘都
鉤刺到小腿,劃破你的身體。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
           "south" : __DIR__"xiaoxi",
           "north" : __DIR__"senlin-2",
           "west" : __DIR__"senlin-3",
           "east" : __DIR__"senlin-4",
	]));

	setup();
}

void init()
{
        add_action("do_look", "look");
}

int do_look(string arg)
{
        object me = this_player();        
        mixed *local;
        local = localtime(time() * 60);
        if (!arg){
        if(local[2] < 3 || local[2] >= 21) {
          message("vision",BLU"這裡黑黝黝一片，\n"
          "越來越多，轉眼便佈滿山谷，有的如流螢飄飛，有的如繁星閃爍。\n"NOR, me);
          }
         return 0;
      }
}
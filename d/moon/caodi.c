// ken 1999.12.9

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "幽香湖旁");
	set("long", @LONG
地勢到此豁然開朗，眼前是各式各樣的奇花異草。左邊是一個小湖，
幽風襲面，清香暗湧。北面則是陡峭的山崖，你這才發現，剛才的
燈光就來自這座山上。
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"caodi2",
  "west" : __DIR__"caodi1",
  "northup" : __DIR__"road1",
]));
	set("coor/x",-30);
	set("coor/y",1050);
	set("coor/z",0);
	setup();
}
void init()
{
   add_action("do_jump", "jump");
}
int do_jump(string arg)
{
   object me, room;
   int mlvl;
   me = this_player();
   if(!arg || arg != "對面") 
    {
     write("你要向哪邊跳？？");
     return 0; 
    }
   mlvl = (int)me->query_skill("move",1);
   if(mlvl < 50)
    {
      message_vision("$N縱身向對面跳了過去，呼呼....\n不好！！！沒跳到！！！\n", me);
    me->unconcious();
      me->set("kee",(int)me->query("kee")/2);
      me->set("eff_kee",(int)me->query("eff_kee")/2);
      me->start_busy(4);
    }
   else{
      message_vision("$N縱身向對面跳了過去，你只覺得耳邊風聲忽忽作響。。。。\n\n", me);
      room = load_object(__DIR__"zz7");
      message_vision("你跳到對面，好累哪。。。\n", me);
      me->move(room);
   }
   return 1;
}

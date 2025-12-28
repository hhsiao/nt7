#include <ansi.h>
#include <room.h>;
inherit ROOM;

void create()
{
  set("short","百丈橋");
  set("long",@LONG
一座長長的索橋，橋身是用樹藤和木板連起來的，一陣風吹來，
橋搖搖欲墜。你小心翼翼的走在橋上，抓緊兩邊的繩索，掂著腳踩著
橋板，這橋顯得又遠又長，你的心"砰砰砰"直跳。
LONG);
     set("outdoors", "天龍寺");
     set("exits",([
           "south" : __DIR__"bzqs",
           "north" : __DIR__"bzqn",
     ]));

     set("coor/x",-390);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}
void init()
{
    object me = this_player();
    if (random(100) > me->query_skill("dodge", 1)){
         message_vision(HIR"一陣大風吹來，$N不小心，從橋上掉了下去。\n"NOR, me);
    if(me->query_skill("dodge", 1) < 30){
       me->receive_damage("qi", 50);
       me->receive_wound("qi",  50);
       } 
    me->set_temp("last_damage_from", "失足從橋上掉下");
    me->move(__DIR__"goudi");
    tell_room(environment(me), "一陣大風吹過，"+me->name()+"失足從橋上掉了下來！\n",({ me }));
    }
}



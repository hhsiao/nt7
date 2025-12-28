inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "漁船中");
        set("long",
"[1;32m一葉小舟漂浮在湖面上，四周群山環繞，風景十分優美。小\n"
"舟很小，僅可乘坐一人，但建造的十分精緻並且牢固，舟上橫放著一對漿。\n"
);
        set("objects",([
                ]));
 
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}   

void init()
{
   add_action("do_sail", "sail");
   add_action("do_dive", "dive");
}

int do_dive()
{
   object me, room;
   me = this_player();

   if( query_temp("marks/gateplace", me)){
      message_vision("$N站起身來，深吸一口氣，一個猛子扎到了湖裡。\n\n", me);
      room = find_object(__DIR__"gongmen");
      if(!objectp(room))  room = load_object(__DIR__"gongmen");
      me->move(room);
      return 1;
   }
   return 0;
}

int do_sail()
{
   object me, land;
   int slvl;
   
   me = this_player();
   slvl = (int)me->query_str();
   land = find_object(__DIR__"lake2");
   if(!objectp(land))
      land=load_object(__DIR__"lake2");
   if (query("exits/up")) return 0;
   if( query_temp("m_success/魚怪", me)){
      if( query_temp("marks/gateplace", me)){
         message_vision("$N輕盈地划著小船，緩緩地靠到了湖邊。\n",me);
         message("vision",me->name()+"輕盈地划著小船，緩緩地靠到了湖邊。\n",land); 
         delete_temp("marks/gateplace", me);
         set("exits/up", __DIR__"lake2");
         set("exits/down", __DIR__"boat", land);
         call_out("boat_leave", 10, land);
         return 1;
      }
      message_vision("$N抄起船漿輕盈地把小船划向湖的東北方。\n", me);
      set_temp("marks/gateplace", 1, me);
      me->start_busy(3);
      return 1;
   }
   if(random(150) < slvl) {
      message_vision("小船緩緩地靠到了湖邊。\n", me);
      message("vision",me->name()+"划著小船，緩緩地靠到了湖邊。\n",land); 
      set("exits/up", __DIR__"lake2");
      set("exits/down", __DIR__"boat", land);
      call_out("boat_leave", 10, land);
      return 1;
   }
   message_vision("$N漫無目的的在湖上划著小船。 \n", me);
   return 1;
}

void boat_leave(object land)
{
   if (query("exits/up")) delete("exits/up");
   if( query("exits/down", land))delete("exits/down", land);
   message("vision","一陣微風拂過，小船蕩離了岸邊。\n",this_object()); 
   message("vision","一陣微風拂過，小船蕩離了岸邊。\n",land); 
}

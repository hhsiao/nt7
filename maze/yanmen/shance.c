#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山側"NOR);
        set("long", @LONG
這裡就是「大宋」軍營駐紮地了，遠遠地可以看見一面大旗，上面書著一個
斗大的隸書「宋」字，再走近些就到軍營了，尋常人還是不要靠近的好，省得被
當成細作捉起來。
LONG
);
        set("defence",120);
        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */   
               "south" :   __DIR__"gate",
               "north"  : __DIR__"shibi",
        ]));    

        set("objects", ([

        ]));
    
        setup();
}

              
/*
void init()
{
      object me=this_player();

      if( me->query_temp("jun_quest/party") == "meng" )
       add_action("do_break","break");
       else
      if( me->query_temp("jun_quest/party") == "song" )
      add_action("do_repair","repair");
}
*/

int do_repair()
{
      object room=this_object(),me=this_player();

      if( me->is_busy() )
      return notify_fail("你正忙著呢！\n");

      if( room->query("defence") > 120 )
      return notify_fail("山側的防禦工事已經修理好了！\n");
      else
      {
       message_vision(
       HIW"$N帶著一支隊伍緊張地搶修著山側的防禦工事！\n"NOR,me);
       room->add("defence",random(me->query_temp("jun_quest/group")));
       me->start_busy(2+random(2));
       return 1;
      }
}

int do_break()
{
      object room=this_object(),me=this_player();

      if( me->is_busy() )        
      return notify_fail("你正忙著呢！\n");

      if( room->query("defence") < 1 )
      {
       room->set("defence",0); 
       write("山側的的防禦已經被擊破了，快衝進去啊！\n");
       return 1; 
      }
      else
      {
       message_vision(
       HIY"$N帶著一支攻城隊伍正加緊攻擊著山側的防禦工事！\n"NOR,me);
       room->add("defence",-random(me->query_temp("jun_quest/group")));
       me->start_busy(2+random(2));
       return 1;
      }
}


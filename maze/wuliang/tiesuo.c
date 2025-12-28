// Room: tiesuo.c
// By River 98/12
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "鐵索橋");
        set("long", @LONG
鐵索橋共是四條鐵索，兩條在下，上鋪木板，以供行走，兩條在旁作為扶
手。一踏上橋，幾條鐵索便即幌動，行到江心，鐵索晃得更加厲害，一瞥眼間，
但見江水蕩蕩，激起無數泡沫，如快馬奔騰般從腳底飛過，只要一個失足，卷
入江水，任你多好的水性也難活命。 
LONG
        );
        set("exits", ([
            "north" : __DIR__"hslin",
            "south" : __DIR__"jiangan",
        ]));       
        set("outdoors", "大理");
        set("coor/x",-280);
  set("coor/y",-280);
   set("coor/z",-20);
   setup(); 
}

void init()
{
        object me=this_player();
        if ( me->query_skill("dodge", 1) < random(50)){
        me->start_busy(2);
        set_temp("last_damage_from", "墜入江中淹", me);
        message_vision(HIR"$N腳下一個不穩，把持不住，摔入滾滾翻騰的瀾滄江內。\n"NOR,me);
        me->unconcious();
//        me->move("/d/death/relax");
        me->die();
        }       
}
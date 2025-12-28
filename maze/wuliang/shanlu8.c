// Modify By River 98/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "荊棘林");
	set("long", @LONG
你信步而行，舉步踏到的盡是矮樹長草，這裡沒有路,每走一步，荊棘都
鉤刺到小腿,劃破你的身體。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
           "south" : __DIR__"xiaoxi",
           "north" : __DIR__"shanlu9",
           "east" : __DIR__"anbian1",
           "west" : __FILE__,
	]));

	set("coor/x",-300);
  set("coor/y",-290);
   set("coor/z",-20);
   setup();
}

void init()
{
       object me = this_player();
        if( random((query("kar", me)))<15
        && me->query_con() < 30){
       set_temp("last_damage_from", "在森林裡筋疲力盡累", me);
         addn("qi", -50, me);
         addn("jingli", -10, me);
         me->receive_wound("jing", 20);
         }
       else{
         addn("qi", -10, me);
         }
}
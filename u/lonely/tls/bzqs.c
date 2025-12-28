#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
  set("short","百丈橋邊");
  set("long",@LONG
你走出了松林，一條深溝橫在面前，擋住了你的去路，溝上有一
座長長的索橋，橋身是用樹藤和木板連起來的，一陣風吹來，橋搖搖
欲墜，幾塊木板還掉了下去。你不由的憂豫起來，止步不前了。一塊
石碑(shibei)立在橋旁。
LONG);
     set("outdoors", "天龍寺");
     set("exits",([
           "north" : __DIR__"bzq",
           "south" : __DIR__"road5",
     ]));

set("objects",([
		__DIR__"npc/liao-kuan" : 1,
		]));


     set("item_desc", ([
                "shibei" :
HIW"


    ※※※※※※※※
    ※※※　　※※※
    ※※※　  ※※※
    ※※※ 百 ※※※
    ※※※    ※※※
    ※※※ 丈 ※※※
    ※※※　  ※※※
    ※※※ 橋 ※※※
    ※※※　  ※※※
    ※※※　　※※※
    ※※※※※※※※\n"NOR,
        ]));

     set("coor/x",-390);
  set("coor/y",-290);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
       string name, new_name;
      //  me = this_player();
        name = me->query("name");
        new_name = name[0..0];

    if (me->query("family/family_name") != "天龍寺" &&
            present("liaokuan chanshi", environment(me)) &&
	    dir =="north")
            return notify_fail("了寬禪師大師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，施主不是天龍弟子，不得過百丈橋到後山。\n");
/*
     if ((new_name != "本" || && present("liaokuan chanshi", environment(me)) && dir =="north")
            return notify_fail("了寬禪師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，你的輩分不夠，不能去後山。\n");
*/
        return ::valid_leave(me, dir);
}

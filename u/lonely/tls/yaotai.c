#include <room.h>

inherit ROOM;

void create()
{
        set("short", "清都瑤臺");
        set("long",@LONG
由此過去一路都是碎石路了，這一帶只准寺內僧侶進入，其它人
等如果沒有方丈許可是不可以來此的。向北可到無無境、雨花院閱讀
經書文獻，向東可至般若臺練習武功，南面是寺內的藥房。
LONG);
        set("outdoors","天龍寺");
        set("exits", ([
                "northup": __DIR__"road2",
                "eastup": __DIR__"banruo",
                "west": __DIR__"men3",
				"south":__DIR__"yaofang",                          
        ]));
			set("objects",([
                __DIR__"npc/liao-qing" : 1,
        ]));
        set("coor/x",-310);
  set("coor/y",-320);
   set("coor/z",30);
   setup();

        create_door("west", "木門", "east", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{	
	mapping myfam;
        myfam = (mapping)me->query("family");
                     
   if ((!myfam || myfam["family_name"] != "天龍寺") && objectp(present("liaoqing chanshi", environment(me)))
      &&(dir == "northup"||dir == "eastup"))
            return notify_fail("了清禪師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，你不是天龍寺弟子，不得入後寺擾亂清修。\n");

if ( !me->query("tls") && objectp(present("liaoqing chanshi", environment(me)))
      &&(dir == "northup"||dir == "eastup"))
            return notify_fail("了清禪師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，你不是天龍寺出家弟子，不得入後寺擾亂清修。\n");
                        
        return ::valid_leave(me, dir);
}
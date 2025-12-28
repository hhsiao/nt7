#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"光佛寶殿"NOR);
        set("long",@LONG
這座大殿正正方方，殿中光線明亮，原來屋頂有一圓洞為琉璃瓦
所制，由四支大紅圓柱托住。殿裡供奉著南無燃燈上古佛祖，金身金
袈，華麗之極。一般香客行到這裡就得止步了，再往後便是寺中僧侶
清修之地。
LONG
        );
       
         set("exits", ([
                "south" : __DIR__"baodian",
                "northdown" : __DIR__"yz6",
                "west" : __DIR__"men2",
                "east" : __DIR__"men1",
        ]));


	set("objects",([
                __DIR__"npc/ben-yin" : 1,
        ]));

        set("coor/x",-350);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
     mapping fam;
 fam = (mapping)me->query("family");
	
	if ( fam && fam["family_name"] != "天龍寺" &&
            present("benyin dashi", environment(me)) &&
			 dir == "northdown")
            return notify_fail("本因大師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，你不是天龍寺弟子，不得入後寺擾亂清修。\n");
    if (fam)
	if ( present("benyin dashi", environment(me)) &&
			 !me->query("tls") &&
		dir == "northdown")
            return notify_fail("本因大師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，你不是天龍寺出家弟子，不得入後寺擾亂清修。\n");                    
        return ::valid_leave(me, dir);
}

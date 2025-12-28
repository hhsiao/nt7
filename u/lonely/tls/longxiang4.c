#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西練武場-龍象臺");
        set("long",@LONG
龍象臺是一個寬大的平臺，是寺中僧侶練習武藝的地方，臺邊
擺有木樁、梅花樁、沙袋、沙盆等練功設施和各種僧家武器。幾個
年輕的僧人正在一旁相互切磋。西邊一扇門通往塔林，門口站著位
禪師。
LONG);
        set("outdoors","dali");
        set("exits", ([
                "east" : __DIR__"longxiang1",
                "west" : __DIR__"shanlu-1",
	             	]));
set("objects",([
		__DIR__"npc/liao-xing" : 1,
			]));

        set("coor/x",-410);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}


int valid_leave(object me, string dir)
{
       string name, new_name;
        name = me->query("name");
        new_name = name[0..0];

    if (me->query("family/family_name") != "天龍寺" &&
            present("liaoxing chanshi", environment(me)) &&
	    dir =="west")
            return notify_fail("了行禪師大師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，施主不是天龍弟子，不得到處亂闖。\n");


        if (new_name != "本" && present("liaoxing chanshi", environment(me)) && dir =="west")
            return notify_fail("了行禪師把手一伸，攔住了你的去路，\n"+
           "說道：阿彌陀佛，你的輩分不夠，不要去塔林擾亂清淨。\n");

        return ::valid_leave(me, dir);
}

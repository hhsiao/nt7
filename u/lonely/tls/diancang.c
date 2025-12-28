#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"點蒼山"NOR);
        set("long", @LONG
點蒼山俗稱蒼山，又叫靈鷲山。南詔時封為中嶽山，北起洱源、鄧川，
南至下關天生橋，東臨洱海，西接漾濞，全長五十多公里。點蒼山有十九座
山峰，峰峰相連，險峻崢嶸。每兩座山峰之間夾一條溪水，共有溪水十八條，
條條清碧。十九座山峰，海拔都在三千米以上，最高的達四千一百多米，山
頂有終年不化的積雪。遠遠望去，宛如白色峨冠，這就是有名的“蒼山雪景”
LONG);
        set("outdoors", "大理");
        set("exits", ([
              "eastup" : __DIR__"dc3",
              "westup" : __DIR__"dc3",
             "northup" : __DIR__"dc3",
           "southwest" : "/d/dali/daliwest/nj",
            "eastdown" : "/d/dali/ximen",
        ]));
        set("coor/x",-350);
  set("coor/y",-420);
   set("coor/z",-10);
   setup();
}

void init()
{
	object me = this_player();

	if(me->query_temp("xuncheng")) me->set_temp("dali_xc/18x",1);
}


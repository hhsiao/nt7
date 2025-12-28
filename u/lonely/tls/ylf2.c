#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"應樂峰北"NOR);
        set("long", @LONG
南面便是點蒼山最高峰應樂峰，山峰直插雲霞，雄偉壯麗。這裡天高
氣寒，山頂還有終年不化的積雪。遠遠望去，宛如白色峨冠，這就是有名
的“蒼山雪景”。
LONG);
        set("outdoors", "dali");

        set("exits", ([             
             "southup" : __DIR__"ylf",
               "north" : __DIR__"shanlu",
        ]));
set("objects", ([
	      "/d/dali/npc/huanglu" : 1,
          "/d/dali/npc/pig" : 1,
	]));

        set("coor/x",-350);
  set("coor/y",-380);
   set("coor/z",20);
   setup();
}
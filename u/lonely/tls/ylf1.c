#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"應樂峰南"NOR);
        set("long", @LONG
北面便是點蒼山最高峰應樂峰，山峰直插雲霞，雄偉壯麗。這裡天高
氣寒，山頂還有終年不化的積雪。遠遠望去，宛如白色峨冠，這就是有名
的“蒼山雪景”。
LONG);
        set("outdoors", "dali");

        set("exits", ([             
             "northup" : __DIR__"ylf",
                "south": __DIR__"dc1",
        ]));

        set("coor/x",-350);
  set("coor/y",-400);
   set("coor/z",20);
   setup();
}
void init()
{
            object me = this_player();
     if(me->query_temp("xuncheng"))
     {
       me->set_temp("dali_xc/ylf1",1);
      }
}



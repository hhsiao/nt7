#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"地藏殿"NOR);
        set("long",@LONG
眼前空地上一座大殿，殿中燈火明亮，殿裡供奉著南無地藏王菩薩，
金身金袈，華麗之極。香案上供著各種鮮花，水果，許多香客都來到這
裡為死去的親人燒香保佑。
LONG);       
        set("exits", ([
                "east" : __DIR__"baodian",
                "south"  : __DIR__"zhonglou",
                "northwest"  : __DIR__"yz5",
	]));
        set("coor/x",-360);
  set("coor/y",-330);
   set("coor/z",20);
   setup();
}
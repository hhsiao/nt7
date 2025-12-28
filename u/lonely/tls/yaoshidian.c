#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"藥師殿"NOR);
        set("long",@LONG
眼前空地上一座大殿，香火興旺，殿裡供奉著南無藥師琉璃光如來，
金身金袈，華麗之極。香案上供著各種鮮花，水果，香油。大殿裡的
香客都在虔誠的磕頭燒香，保佑自己生病的親人早日康復。
LONG
        );
       
        set("exits", ([
                "west" : __DIR__"baodian",
                "south"  : __DIR__"gulou",
                "northeast"  : __DIR__"yz4",
        ]));


	set("objects",([
                __DIR__"npc/guest" : 2,
        ]));

        set("coor/x",-340);
  set("coor/y",-330);
   set("coor/z",30);
   setup();
}
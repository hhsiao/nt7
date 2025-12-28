#include <ansi.h>
#include <wanted.h>
inherit ROOM;

void create()
{
        set("short", HIY"崇聖寺"NOR);
        set("long", @LONG
崇聖寺在大理城外點蒼山中嶽峰之北，因段氏歷代祖先做皇帝的，往
往避位為僧，都是在這崇聖寺中出家，因此崇聖寺便是大理皇室的家廟，
於全國諸寺之中最是尊榮，所以又稱之為天龍寺，大門氣勢恢弘，上掛一
巨幅匾額(biane)。這裡揹負蒼山，面臨洱水，極佔形勝。
LONG);
        set("outdoors", "天龍寺");

        set("item_desc",([
	  "biane" : "\n
            ※※※※※※※※※※※※※※※※※※※※※※
            ※※※※　　　　　　　　　　　　　　※※※※       
            ※※※※     "HIY"崇      聖      寺"NOR"     ※※※※
            ※※※※　　　　　　　　　　　　　　※※※※
            ※※※※※※※※※※※※※※※※※※※※※※\n\n",
			  ]));	

        set("exits", ([             
               "enter" : __DIR__"road",
               "south" : __DIR__"shanlu",
        ]));

        set("coor/x",-350);
  set("coor/y",-360);
   set("coor/z",20);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "enter" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}

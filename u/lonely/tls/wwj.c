#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "無無境");
        set("long",@LONG
忽然眼前景物一變，一座半人高矮圍牆裡竹林似海，幽靜無比，小路
從中輕輕穿過，通向院外的雨花院。這裡種植的全是西南名竹--雲竹。每
當輕風吹過，吹得竹幹搖擺，如雲如海，在你身邊一浪浪撫過，使你心中
似有所動。東邊一條石板路延伸向遠方。
LONG);
	set("outdoors","天龍寺");
        set("exits", ([
		"north": __DIR__"yuhua",
		"south": __DIR__"road2", 
	        "east": __DIR__"road3",
		]));
        set("coor/x",-310);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}

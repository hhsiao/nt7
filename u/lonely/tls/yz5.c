#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"青竹院"NOR);
        set("long", @LONG
這裡一座遍植青竹的小院子，當中一條小路向北通往無住塔，白石地
面打掃得非常乾淨，輕風吹過，只吹得竹葉隨風飄動，發出沙沙的聲響，
卻帶不起一絲灰塵。
LONG);
        set("outdoors", "dali");

       set("exits", ([                           
               "east" : __DIR__"men2",
               "west" : __DIR__"men4",
               "north" : __DIR__"ta3",
               "southeast"  : __DIR__"dizangdian",
        ]));
set("objects",([
		__DIR__"npc/guest" : 2,
		__DIR__"npc/shami" : 1,
		]));
        set("coor/x",-370);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
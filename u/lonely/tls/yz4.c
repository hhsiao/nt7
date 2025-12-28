#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"青竹院"NOR);
        set("long", @LONG
這裡一座遍植青竹的小院子，當中一條小路向北通往無相塔，白
石地面打掃得非常乾淨，輕風吹過，只吹得竹葉隨風飄動，發出沙沙
的聲響，卻帶不起一絲灰塵。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([                           
               "west" : __DIR__"men1",
               "east" : __DIR__"men3",
               "north" : __DIR__"ta2",
               "southwest"  : __DIR__"yaoshidian",
        ]));
        set("coor/x",-330);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
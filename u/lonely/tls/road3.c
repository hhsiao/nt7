#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"白石路"NOR);
        set("long", @LONG
這裡又是一段白石路，石面平滑，打掃得乾乾淨淨。路旁種有各式花
草，兩株參天大樹分立左右兩邊。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([             
               "west" : __DIR__"wwj",
               "east" : __DIR__"lang",               
        ]));

        set("coor/x",-300);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}
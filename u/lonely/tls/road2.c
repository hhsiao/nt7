#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"白石路"NOR);
        set("long", @LONG
這裡又是一段白石路，石面平滑，打掃得乾乾淨淨。路旁種有各
式花草，兩株參天大樹分立左右兩邊。北面是無無境，往南是般若臺、
清都瑤臺等地。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([             
               "north" : __DIR__"wwj",
               "southdown" : __DIR__"yaotai",
   	       "southeast" : __DIR__"banruo",            
        ]));
        set("coor/x",-310);
  set("coor/y",-310);
   set("coor/z",40);
   setup();
}

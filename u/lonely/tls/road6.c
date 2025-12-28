#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"白石階"NOR);
        set("long", @LONG
這裡是依山而建的一段石階路，是用點蒼山特有的白石砌成，
路很陡很險。左面就是懸崖，一陣大風吹來，你不由的晃了幾晃，
嚇出一身冷汗。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([             
               "southdown" : __DIR__"dmg",               
        ]));
        set("coor/x",-360);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}
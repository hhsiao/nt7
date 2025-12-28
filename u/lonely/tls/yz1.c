#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"松樹院"NOR);
        set("long", @LONG
這裡是石路旁的一座小院子，松樹成蔭，地上撒滿了飄落的松針。
一旁擺有幾隻石凳，是準備給進香客們歇腳用的。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([                           
               "north" : __DIR__"zt1",
               "east" : __DIR__"road",
        ]));
        set("coor/x",-360);
  set("coor/y",-360);
   set("coor/z",20);
   setup();
}

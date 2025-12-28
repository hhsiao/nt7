#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"斑竹院"NOR);
        set("long", @LONG
這裡是石路旁的一座小院子，院內遍植湘妃斑竹，輕風吹過，竹
幹隨風飄動，發出沙沙的聲響。一旁擺有幾隻石凳，是準備給進香客
們歇腳用的。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([                           
               "north" : __DIR__"zt",
               "west" : __DIR__"road",
        ]));
        set("coor/x",-340);
  set("coor/y",-360);
   set("coor/z",30);
   setup();
}

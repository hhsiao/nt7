#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"松樹院"NOR);
        set("long", @LONG
這裡一座遍植青竹的小院子，當中一條小路通往千尋寶塔，白石
地面打掃得非常乾淨，輕風吹過，只吹得竹葉隨風飄動，發出沙沙的
聲響，卻帶不起一絲灰塵。東西各有一條小道。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([                           
               "southup" : __DIR__"gfd",
               "north" : __DIR__"ta1",
               "east" : __DIR__"ytd",
               "west" : __DIR__"sjt",
        ]));
        set("coor/x",-350);
  set("coor/y",-310);
   set("coor/z",20);
   setup();
}
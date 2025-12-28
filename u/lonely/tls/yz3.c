#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"青竹院"NOR);
        set("long", @LONG
這裡一座遍植青竹的小院子，當中一條小路通往後山上，白石地
面打掃得非常乾淨，輕風吹過，只吹得竹葉隨風飄動，發出沙沙的聲
響，卻帶不起一絲灰塵。東西各有一條小道。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([                           
               "south" : __DIR__"ta1",
               "northup" : __DIR__"road4",
               "west" : __DIR__"gmd",
               "east" : __DIR__"xmd",
        ]));
        set("coor/x",-350);
  set("coor/y",-290);
   set("coor/z",20);
   setup();
}
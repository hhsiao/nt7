#include <ansi.h>
inherit ROOM;

void create()
{
  set("short","百丈橋");
  set("long",@LONG
一條深溝橫在面前，擋住了你的去路，溝上有一座長長的索橋，
橋身是用樹藤和木板連起來的，一陣風吹來，橋搖搖欲墜，幾塊木板
還掉了下去。你不由的憂豫起來，止步不前了。一塊石碑(shibei)立
在橋旁。
LONG);
     set("outdoors", "天龍寺");
     set("exits",([
           "north" : __DIR__"fqg",
           "south" : __DIR__"bzq",
           "east" : __DIR__"wxj",
     ]));
     set("item_desc", ([
                "shibei" :HIW"


    ※※※※※※※※
    ※※※　　※※※
    ※※※　  ※※※
    ※※※ 百 ※※※
    ※※※    ※※※
    ※※※ 丈 ※※※
    ※※※　  ※※※
    ※※※ 橋 ※※※
    ※※※　  ※※※
    ※※※　　※※※
    ※※※※※※※※\n"NOR,
        ]));

     set("coor/x",-390);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"白石路"NOR);
        set("long", @LONG
這裡是天龍寺後山僧人和俗家弟子作休之處，西邊傳來菜飯的香
氣，東邊是天龍寺的武器房。不少弟子來此挑選自己趁手的兵器。東
面是慈悲院，西邊山上是鬥母宮，北邊是天龍僧人睡房。
LONG);
        set("outdoors", "天龍寺");
        set("exits", ([             
               "west" : __DIR__"dmg",
               "east" : __DIR__"cby",  
               "north" : __DIR__"sroom",                            
               "southdown" : __DIR__"yz3",                           
        ]));
        set("coor/x",-350);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}
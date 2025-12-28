inherit ROOM;

void create()
{
  set("short","松樹林");
  set("long",@LONG
這裡是一片茂密的松樹林，松樹高大，枝葉茂盛，你一走進來差
點便迷失了方向。這裡灌木叢生，路都給擋住了。
LONG);

     set("outdoors", "天龍寺");
     set("exits",([
           "east" : __DIR__"songlin-2",
           "west" : __DIR__"songlin-3",
           "north" : __DIR__"songlin-4",
           "south" : __DIR__"songlin-1",
     ]));
    
     set("coor/x",-310);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}
#include "songlin.h"
inherit ROOM;

void create()
{
  set("short","松樹林");
  set("long",@LONG
這裡是一片茂密的松樹林，松樹高大，枝葉茂盛，你一走進來差
點便迷失了方向。一條長廊由西向東通往松林深處。
LONG);

     set("outdoors", "天龍寺");
     set("exits",([
           "east" : __FILE__,
           "west" : __FILE__,
           "north" : __DIR__"songlin2",
           "south" : __DIR__"songlin2",
     ]));
    
     set("coor/x",-300);
  set("coor/y",-280);
   set("coor/z",40);
   setup();
}
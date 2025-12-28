inherit ROOM;

void create()
{
        set("short","長廊");
        set("long",@LONG
這是一條非常幽靜的長廊。西邊小路通往無無境，東邊過去是寺
院深處的松林。
LONG);
     set("exits",([
        "west" : __DIR__"road3",
        "east" : __DIR__"songlin",
    ]));
    set("coor/x",-290);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}





inherit ROOM;

void create()
{
  set("short","長廊");
  set("long",@LONG
這裡松樹林裡一條非常幽靜的長廊，往西直通無無境等地。長廊
盡頭處有一簡屋，材料天然，與這茂密的松樹林混為一體。
LONG);

   set("exits",([
      "west" : __DIR__"songlin",
      "north" : __DIR__"songlin1",
      "enter" : __DIR__"monitang",
      "south" : __DIR__"songlin2",
     ]));
 set("coor/x",-270);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}





inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一條長長的石板路上，道旁古樹參天，鳥鳴不絕，前面是
一片大松林，這條路一直通向百丈橋，路上冷冷清請，偶爾見幾個僧
人從松林中穿出來。
LONG);
	set("exits", ([
           "north" : __DIR__"bzqs",
           "south" : __DIR__"shiyuan",   
        ]));
	set("outdoors", "天龍寺");
	set("coor/x",-390);
  set("coor/y",-300);
   set("coor/z",30);
   setup();
}

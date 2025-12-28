inherit ROOM;

void create()
{
        set("short", "鬥母宮");
        set("long",@LONG
這裡是天龍寺裡最高的地方了，再往上都是險峻的懸崖了，這座
小殿依山而建，殿內燈火通明，你站在門口，遠眺天龍寺，只見一片
殿堂連綿不絕，甚是浩大。
LONG);
        set("exits", ([
               "east" : __DIR__"road4",
//               "south" : __DIR__"yaofang",
               "north" : __DIR__"road6",
	]));
        set("coor/x",-360);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}

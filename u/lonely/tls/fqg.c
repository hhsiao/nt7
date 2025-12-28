inherit ROOM;

void create()
{
  set("short","飛泉溝");
  set("long",@LONG
這裡已是天龍寺的後山很偏僻的地方了，一道瀑布從天而降，空
氣裡充滿了瀑布濺起的水霧，在陽光直射下，幻出一道道七色彩虹，
瀑布順著山溝流向南面的百丈橋，路邊大石林立，古樹參天。
LONG);
     set("outdoors", "天龍寺");
     set("exits",([
           "northup" : __DIR__"wxt",
           "south" : __DIR__"bzqn",
               ]));

     set("coor/x",-390);
  set("coor/y",-260);
   set("coor/z",30);
   setup();
}
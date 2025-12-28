inherit ROOM;

void create()
{
        set("short", "兜率大士院");
        set("long",@LONG
兜率大士院供奉的是八部天龍、五百阿羅、三千揭啼。這裡煙霧
瀰漫，都是香客門所進的天竺檀香。幾個知客僧正忙得不亦樂乎。由
此向南是三無宮，西往清音閣，北至後山。
LONG);
        set("exits", ([              
              "southdown" : __DIR__"3wg",
              "west" : __DIR__"qxg",
              "north" : __DIR__"road5",
	]));	
        set("coor/x",-390);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}

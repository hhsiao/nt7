inherit ROOM;

void create()
{
	set("short", "鼓樓");
	set("long", @LONG
這是一座磚木結構的小樓，飛簷翹翎，簷角上掛滿了一串串小銅
鈴，隨風叮叮作響。牆上鏤空雕繪著無數佛陀們的坐像。一個個形態
維肖。樓內高懸者一個大鼓，鼓身上繪有佛祖釋迦牟尼於菩提樹下說
法的彩繪。
LONG);
	set("exits", ([
		"west" : __DIR__"road1",
                "south"  : __DIR__"zt",
                "north"  : __DIR__"yaoshidian",
	]));
	set("coor/x",-340);
  set("coor/y",-340);
   set("coor/z",30);
   setup();
}






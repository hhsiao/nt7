inherit ROOM;

void create()
{
        set("short", "無淨閣");
        set("long",@LONG
這是歷代大理王侯女眷前來進香還願時休息的地方。閣內檀象
寶爐，軟榻矮几，一應俱全，清靜之中隱然透出一絲富貴之象。
LONG);
        set("sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([
		"south": __DIR__"men1",    			
        ]));
        set("coor/x",-340);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}

inherit ROOM;

void create()
{
        set("short", "無我閣");
        set("long",@LONG
這是歷代大理王侯前來進香還願時休息的地方。閣內檀象寶爐，
軟榻矮几，一應俱全，清靜之中隱然透出一絲富貴之象。
LONG);
        set("no_fight",1);
        set("sleep_room", 1);
        set("exits", ([
		"south": __DIR__"men2",
        ]));
        set("coor/x",-360);
  set("coor/y",-310);
   set("coor/z",20);
   setup();
}

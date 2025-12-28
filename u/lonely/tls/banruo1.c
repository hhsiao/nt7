inherit ROOM;
void create()
{
        set("short","般若臺");
        set("long",@LONG
般若臺是一個寬大的平臺，是寺中弟子練習武藝的地方，臺邊
擺有木樁、梅花樁、沙袋、沙盆等練功設施和各種僧家武器。幾名
年輕的出家弟子正在一旁相互切磋。
LONG);
        set("outdoors","天龍寺");
        set("exits", ([
                "west" : __DIR__"banruo",
              
        ]));
		set("objects",([
		__DIR__"npc/dizi-f" : 1,
	__DIR__"npc/dizi-m" : 1,
			]) );
        set("coor/x",-290);
  set("coor/y",-320);
   set("coor/z",40);
   setup();
}

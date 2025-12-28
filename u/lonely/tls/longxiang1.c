inherit ROOM;

void create()
{
        set("short", "龍象臺");
        set("long",@LONG
龍象臺是一個寬大的平臺，是寺中俗家弟子練習武藝的地方，
臺邊擺有木樁、梅花樁、沙袋、沙盆等練功設施和各種僧家武器。
幾名年輕的俗家弟子正在一旁相互切磋。
LONG);
        set("outdoors","天龍寺");
        set("exits", ([
                "eastdown" : __DIR__"3wg",
                "west" : __DIR__"longxiang4",
	        "northup" : __DIR__"longxiang2",
                "southdown" : __DIR__"longxiang3",
           
       	]));
       
        set("coor/x",-400);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}

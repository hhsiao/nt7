inherit ROOM;

void create()
{
        set("short", "西練武場-龍象臺");
        set("long",@LONG
龍象臺是一個寬大的平臺，是寺中僧侶練習武藝的地方，臺邊
擺有木樁、梅花樁、沙袋、沙盆等練功設施和各種僧家武器。幾個
年輕的僧人正在一旁相互切磋。
LONG);
        set("outdoors","dali");
        set("exits", ([
               "northup" : __DIR__"longxiang1",
           
       	]));
        set("coor/x",-400);
  set("coor/y",-330);
   set("coor/z",20);
   setup();
}

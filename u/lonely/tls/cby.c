inherit ROOM;

void create()
{
        set("short", "慈悲院");
        set("long",@LONG
這是僧人們點化頑徒的地方。不少江湖豪客由於厭倦了打打殺殺
的日子，來到此處落髮為僧，叛依佛門。牆上一幅佛祖神像，兩邊各
有一條幅，上書：放下屠刀，立地成佛。此處東面是個兵器房，北面
是物品房。
LONG);
        set("exits", ([
                "east" : __DIR__"bingqi",
		"west" : __DIR__"road4",
		"north" : __DIR__"wuping",
	]));    
        set("coor/x",-340);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}

// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
這裡是密道，前面隱約能看見亮光，聽見一些聲音，看樣子到洞口了。你
走到洞口前，立刻看見了熟悉的道路。
LONG
	); 

	set("exits", ([
	      "out" : "/d/dali/shanlu3",
              "northup" : __DIR__"midao4",
	]));

	setup(); 
}

int valid_leave(object me, string dir)
{
      if ( dir == "out"){
       write("\n你出得地道，強光閃耀，一時之間竟然睜不開眼。\n\n");
       }
       return 1;
//     return ::valid_leave(me, dir);
}
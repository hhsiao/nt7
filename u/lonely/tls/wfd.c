// /u/cool/tls/wanfodong.c
// cool 1998.2.13

inherit ROOM;

void create()
{
	set("short", "萬佛洞");
	set("long", @LONG
你走出忘雪亭來到山壁邊，眼前一座古洞，洞口上面書有三個大
字“萬佛洞”，這洞隱藏在寺後深處，尋常人等恐怕找也找不到這裡。
LONG);
	set("exits", ([
	      "up" : __DIR__"wxt",
              "enter" : __DIR__"wfd2",	
        ]));
	set("coor/x",-390);
  set("coor/y",-250);
   set("coor/z",30);
   setup();
}


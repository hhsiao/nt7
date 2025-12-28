// Room: /dali/dong1.c
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "石室");
	set("long", @LONG
所處之地是座圓型石室，左邊石壁上鑲著一塊水晶，約有銅盆大小，光亮
即由水晶中透入。向外瞧去，可看到水流不停晃動，原來這裡地處水底。室內
有一石桌，塵土寸積，不知已有多少年無人來此。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	   "enter" : __DIR__"dong2",
           "out" : __DIR__"dongkou",
           "up" : __DIR__"taijie",
        ]));
	set("no_clean_up", 0);

	setup();
}
// Room: banshan4.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "半山");
	set("long", @LONG
這山崖似乎無窮無盡，幸好崖縫中有不少砂石，不至於一溜而下，越到底
越是平緩，不再是危崖筆立，但耳中轟隆轟隆的聲音越來越響，只覺水珠如下
大雨濺到臉上，隱隱生疼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "down" : __DIR__"gudi",
        ]));
	set("no_clean_up", 0);
        set("outdoors", "大理");
	setup();
}

void init()
{	
	add_action("do_down", "pa");
}

int do_down(string arg)
{
	object me = this_player();
        if (!arg || arg!="down") return 0;
	message_vision(HIR "$N伏在坡上，半滾半爬，一下子溜到了谷底。\n" NOR, me);
	me->move(__DIR__"gudi");
	return 1;
}
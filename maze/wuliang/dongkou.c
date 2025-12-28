// dongkou.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

string look_huan();
void create()
{
	set("short", "洞口");
	set("long", @LONG
走得十餘步，洞中已無絲毫光亮，但覺腳下平整，便似走在石板路上一樣，
洞中道路必是經過人工修整，只是道路不住的向下傾斜，顯是越走越低突然之
間，你碰到什麼，有圓物鐺的一下，聲音清亮，原來是個門環(huan)
LONG
	);
        set("exits", ([
		"out" : __DIR__"shibi",
        ]));
        set("outdoors", "大理");
	set("item_desc", ([
             "huan" : "門環在一扇大門上，似以鋼鐵鑄成，但裡面並未插上。\n",
	]));

	setup();
}

void init()
{
        add_action("do_knock", "knock");
        add_action("do_knock", "qiao");
        add_action("do_enter", "push");
        add_action("do_enter", "tui");
}

int do_knock(string arg)
{
	object me;
 	me = this_player();
        if (!arg ||arg!="huan") return 0;
	message_vision("$N提起門環當的敲了一下，但門內無人答應。\n" , me);
        set_temp("knock_door", 1, me);
	return 1;
}

int do_enter(string arg)
{
	object me = this_player();
        if (!arg ||arg!="huan") return 0;
        if( query_temp("knock_door", me)){
        message_vision("$N手勁使將上去，那門便緩緩的開了。\n"  , me);
	set("exits/enter", __DIR__"dong1");
        return 1; 
        }
      return notify_fail("就這樣貿然闖入不太好吧。\n");
}
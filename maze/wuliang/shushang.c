// shushang.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "樹上");
	set("long", @LONG
你現在的處境還是不妙，樹枝不停地發出『吱吱』的響聲，隨時會斷你人
還是掛在半空，不住搖晃，向下望去，只見深谷中雲霧瀰漫，見不到盡頭，看
那崖壁好象有條細縫(feng)。
LONG
	);
	set("item_desc", ([
	   "feng" : "你的腳勉強可以夠到。\n"
        ]));
        set("outdoors", "大理");

	setup();
}

void init()
{
        add_action("do_move", "gou");
        add_action("do_move", "reach");
        add_action("do_down", "move");
        add_action("do_down", "pa");
}

int do_down(string arg)
{
	object me;
 	me = this_player();
	message_vision(HIR "$N繼續爬向崖壁，『啊～～不好！』樹枝斷了，$N急速向下墜去。\n" NOR, me);
        me->unconcious();
        me->move("/d/dali/shanlu3");
	return 1;
}

int do_move(string arg)
{
	object me = this_player();
        if (!arg || arg!="feng") return 0;
        message_vision(HIR "$N小心地攀住樹枝，向崖縫用腳探去，勉強攀援而下。\n"  NOR, me);
        me->move(__DIR__"banshan1");
        return 1; 
}
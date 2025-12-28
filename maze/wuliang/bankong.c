// bankong.c
// bbb 1997/6/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "半空");
	set("long", @LONG
你嚇出一身冷汗，不管全身的疼痛，伸出手牢牢抱住古松的樹枝，登時掛
在半空，不住搖晃，向下望去，只見深谷中雲霧瀰漫，還是不見盡頭，周圍只
有樹枝在不停的搖晃。下面是懸崖，再往下掉看來危險萬分。
LONG
	);
        set("outdoors", "大理");
	setup();
}

void init()
{
        add_action("do_move", "pa");
        add_action("do_move", "climb");
        add_action("do_move", "move");
        add_action("do_down", "down");
}

int do_down(string arg)
{
	object me;
 	me = this_player();
	message_vision(HIR "$N鬆開雙手，身子立即急速向下墜去，耳邊風聲呼呼。\n" NOR, me);
        me->unconcious();
        me->move("/d/dali/shanlu3");
	return 1;
}

int do_move(string arg)
{
	object me = this_player();
        if ( !arg || arg!="yabi") return 0;
        message_vision("$N小心地攀住樹枝，向崖壁爬去。\n" , me);
        me->move(__DIR__"shushang");
        return 1; 
}
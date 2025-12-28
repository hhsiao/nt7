#include <ansi.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "鐘樓");
	set("long", @LONG
這是一座磚木結構的小樓，飛簷翹翎，簷角上掛滿了一串串小銅鈴，隨風
叮叮作響。牆上鏤空雕繪著無數佛陀們的坐像。一個個形態維肖。樓內高懸者
一個大鐘(zhong)，看樣子不下上千斤，鐘身上鑄有金剛經文，這鐘一旦敲響，
在大理城內都可聞見。
LONG
        );

	set("exits", ([
		"east" : __DIR__"road1",
		"south"  : __DIR__"zt1",
		"north"  : __DIR__"dizangdian",
	]));

	set("item_desc",([
		"zhong"		:	"這口鐘很大，每天都有人來敲(qiao)的",
	]));

	set("objects",([
		__DIR__"npc/guest" : 1,
	]));

	set("outdoors", "天龍寺");
	setup();
}

void init()
{
	add_action("do_knock", "knock");
	add_action("do_knock", "qiao");
}

int do_knock(string arg)
{       
	mixed *local;
	object me;
	int costj, costq;
	me = this_player();

	local = localtime(time() * 60);
	            
	if (me->is_busy()) {
		write("你現在正忙著呢!\n");
		return 1;
	}

	if (me->is_fighting()) {
		write("你正在戰鬥中,無法專心幹活!\n");
		return 1;
	}
          
	if (!( present("zhong chui", this_player())))
		return notify_fail("你試了下，顯然用手是撞不響鐘的。\n");

	if ( !arg || arg != "zhong" ) {
		write("你要撞什麼？\n");
		return 1;
	}
        
	if (local[2] < 6 || local[2] >= 21) {
		message_vision("『咣……』的一聲,一個小和尚突然外面跑過來說：“現在是休息時間，請毋敲鐘！”\n"+
				"小和尚見$N放下鍾錘，打了個哈乞，走了出去。\n",me);
		return 1;
	}

	costj = (int)me->query("con")/3;
	costq = (int)me->query("str")/2;

	if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq) {
		message_vision("鐘聲一響，$N被巨大的轟鳴聲震的昏了過去。\n",me);
		me->unconcious();
		return 1;
	}
	if ((int)me->query_skill("force",1) < 30 ) {
		message_vision("『咣……』的一聲，$N被震的昏了過去。\n",me);
		me->unconcious();
		return 1;
	}          
	me->receive_damage("jingli", costj);
	me->add("qi", -costq);       

	message_vision("$N敲了一下大鐘，『咣……』聲音傳遍整個寺廟。\n", me);
		
	if ((int)me->query_skill("force", 1) < 101 ) {
		write("鐘聲震得你眼前發暈，你深吸了一口氣，暗運內功抵擋。\n");
		me->improve_skill("force", (int)me->query_int()/2);
	}
	else {
		write("鐘聲響起，你不由的心中暗起肅穆之心。\n");
	}
	return 1;
}

#include <ansi.h>
#include <room.h>
#include <wanted.h>
#define QUESTDIR1 "quest/天龍八部/凌波微步篇/"
#define TIME_TICK (time()*60)

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你信步而行，舉步踏到的盡是矮樹長草，這裡沒有路,每走一步，荊棘都
鉤刺到小腿,劃破你的身體。
LONG
        );
	set("outdoors", "大理");

	set("exits", ([
		"south" : __DIR__"shanlu11",
		"north" : __DIR__"shanlu11",
		"west" : __DIR__"shanlu11",
		"east" : __DIR__"shanlu11",
	]));

	setup();
}

void init()
{
	object me = this_player();

	if( query(QUESTDIR1+"pass_shanlu", me )
	 && me->query_skill("lingbo-weibu", 1) < 140
	 && ! is_wanted(me)){
		me->move("/maze/wuliang/gaoshan", 1);
		message_vision(HIR"$N熟悉地繞過森林，來到一個高山上。\n"NOR, me);
	}
	if( random(query("kar", me))<10 && me->query_con()<30){
set_temp("last_damage_from", "在森林裡筋疲力盡累", 		me);
addn("qi", -30, 		me);
addn("jingli", -10, 		me);
		me->receive_wound("jing", 20);
	}
	else {
addn("qi", -20, 		me);
	}
	add_action("do_look", "look");
}

int do_look(string arg)
{
	object me = this_player();
	mixed *local;
	local = localtime(TIME_TICK);
	if(local[2] < 6 &&random(6)<2) {
	message("vision",BLU"天黑了,這裡黑黝黝一片，伸手不見五指,你四處亂走著,心裡充滿恐懼.\n"
				"突然傳來幾聲野獸的嚎叫,你嚇的哭了起來.\n"NOR, me);
	}
}
int valid_leave(object me, string dir)
{
	mixed *local;
	int i = 0;

	local = localtime(TIME_TICK);

	if (dir == "west")
addn_temp("mark/steps", 1, 		me);
	if (dir == "south")
addn_temp("mark/step", -1, 		me);
	if (dir == "east")
addn_temp("mark/steps", -1, 		me);
	if (dir == "north")
addn_temp("mark/step", 1, 		me);

/**for 營救段譽 ***/
// Modify By River 關於不能太簡單獲得 lbwb ，只給三次機會

// Modify By tangfeng Quest本身誰可以解的，問題是拿到帛卷是否領悟到凌波微步

	if( query_temp("mark/steps", me) == query_temp(QUESTDIR1+"steps", me )
	 && query_temp("mark/step", me) == query_temp(QUESTDIR1+"step", me) )
		i = 1;
	if( wizardp(me))  tell_object(me,HIR"\ni="+i+".\n"NOR);
	if (i
		&& local[2] < 6
		 && query_temp(QUESTDIR1+"yingjiu", me )
		&& !me->query_condition("killer"))
	{
		me->move("/maze/wuliang/gaoshan");
set(QUESTDIR1+"pass_shanlu", 1, 		me);
delete_temp("mark/steps", 		me);
delete_temp("mark/step", 		me);
		return notify_fail(HIR"\n你走到了一個高山上。\n"NOR);
	}
	if( (query_temp("mark/steps", me)<-10
	 || query_temp("mark/step", me)<-10
 	 || query_temp("mark/steps", me)>12
	 || query_temp("mark/step", me)>12) && !random(20) )
	{
		if( query_temp(QUESTDIR1+"yingjiu", me))set("quest/天龍八部/time", time(), me);
		me->move("/maze/wuliang/xiaoxi");
delete_temp("mark/steps", 		me);
delete_temp("mark/step", 		me);
		if( query_temp(QUESTDIR1+"yingjiu", me)){
delete_temp("quest/天龍八部", 			me);
			me->delete_temp("quest/busy");//任務衝突標誌取消
			return notify_fail(HIW"\n你筋疲力盡地走出這段山路，沮喪地發現自己怎麼也找不到四大惡人的行蹤。\n"NOR);
		}
		else return notify_fail(HIY"你筋疲力盡，終於走出了這段山路。\n"NOR);
	}
	return ::valid_leave(me, dir);
}
/*
int valid_leave(object me, string dir)
{
	mixed *local;
	int i = 0;

	local = localtime(TIME_TICK);

	if (dir == "west")
addn_temp("mark/steps", 1, 		me);
	if (dir == "south")
addn_temp("mark/step", -1, 		me);
	if (dir == "east")
addn_temp("mark/steps", -1, 		me);
	if (dir == "north")
addn_temp("mark/step", 1, 		me);

	if( query_temp("mark/steps", me) == query_temp("duanyu/steps", me )
	 && query_temp("mark/step", me) == query_temp("duanyu/step", me) )
		i = 1;
	if (i
	 && (random(query("kar", me))+random(query("int", me)))>50
	 && (random(me->query_con(1))+random(me->query_int(1))) > 75
	 && local[2] < 6
	 && local[2] >= 3
	 && query_temp("duanyu/find2", me)){
		me->move(__DIR__"gaoshan");
		log_file("quest/lbwb",
			sprintf("%-18s順利通過山路，走上尋找凌波微步之路，福：%d，悟：%d，根：%d，悟：%d。\n",
				me->name(1)+"("+capitalize(getuid(me))+")",
query("kar", 				me),
query("int", 				me),
				me->query_con(1),
				me->query_int(1)
			), me
		);
set("quest/dali/shanlu", 1, 		me);
delete_temp("mark/steps", 		me);
delete_temp("mark/step", 		me);
		return notify_fail("你走到了一個高山上。\n");
	}
	if( query_temp("mark/steps", me)<-8
	 || query_temp("mark/step", me)<-8
 	 || query_temp("mark/steps", me)>10
	 || query_temp("mark/step", me)>10
	 || i && !random(30)) {
		if( query_temp("duanyu/find2", me)){
addn("quest/dali/fail", 1, 			me);
set("quest/dali/time", time(), 			me);
			log_file("quest/lbwb",
				sprintf("%-18s第%d次機會沒有掌握，未能順利通過山路。\n",
					me->name(1)+"("+capitalize(getuid(me))+")",
query("quest/dali/fail", 					me )
				),
			me);
		}
		me->move(__DIR__"xiaoxi");
delete_temp("mark/steps", 		me);
delete_temp("mark/step", 		me);
		if( query_temp("duanyu/find2", me)){
delete_temp("duanyu", 			me);
			return notify_fail(HIW"\n你筋疲力盡地走出這段山路，沮喪地發現自己怎麼也找不到四大惡人的行蹤。\n"NOR);
		}
		else {
delete_temp("duanyu", 			me);
			return notify_fail("你筋疲力盡，終於走出了這段山路。\n");
		}
	}
	return ::valid_leave(me, dir);
}
*/

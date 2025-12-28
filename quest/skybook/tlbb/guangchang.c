// Room: /d/shaolin/guangchang1.c
// Date: YZC 96/01/19

#include <ansi.h>
#include <wanted.h>

inherit ROOM;

void init();
int do_open();
string look_gate();
#define QUESTDIR3 "quest/天龍八部/蕭峰身世篇/"
#define QUESTDIR5 "quest/天龍八部/復興天下篇/"

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裡是少林寺前的廣場，整個廣場由大塊的青石鋪成，極為平坦。但因年
代久遠，都有些破損。叢叢小草從石板的縫隙中長了出來。廣場周圍都是密密
的松樹林，四角上各放了幾塊石碑，字跡都甚為模糊。正前方黃牆碧瓦，飛簷
翹檁，正中一道二丈來寬，三丈來高的硃紅杉木包銅大門(gate)。上方一塊大
匾，龍飛鳳舞地書著『[1;33m少林寺[0;37;0m』三個大字。寺前三三兩兩的站著幾個僧人。
LONG
    );

	set("exits", ([
		"east" : __DIR__"gchange",
		"south" : __DIR__"shifang",
		"west" : __DIR__"gchangw",
	]));

	set("outdoors", "shaolin");
	set("item_desc",([
		"gate"        :    (: look_gate :),
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-fa" : 1,
	]));

	setup();
	"/clone/board/shaolin_b"->foo();
}

void init()
{
	object me;
  me = this_player();
  if(!me->query_condition("killer") && me->query(QUESTDIR3+"bad") && me->query_temp(QUESTDIR5+"zhangxing") && !me->query_temp(QUESTDIR5+"dagouzhen"))
  {
   tell_object(me,HIC"\n你總算走出少林寺，來到山門殿廣場。突然你又有一種不妙的預感。\n"NOR); 
   message_vision(WHT"山下匆匆走來一個人，向$N一拱手道：“嘿嘿，施主如此兇狠，還是留在少林潛修佛法得好阿。”\n"NOR,me);
   me->move("/d/gb/dagouzhen");
   tell_object(me,HIR"你疑惑了一下，卻發現四周圍上一圈人，似乎是丐幫打狗陣法。\n"NOR);
   log_file("quest/TLBB", sprintf("%s(%s)被關進打狗陣。經驗：%d。\n", me->name(1),me->query("id"), me->query("combat_exp")) );
   return;
  }
	add_action("do_knock", "knock");
}

int close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");
	if(objectp(room)) {
	delete("exits/north");
	message("vision", "乒地一聲，裡面有人把大門關上了。\n", this_object());
	room->delete("exits/south");
	if (objectp(present("qingfa biqiu", room)))
		message("vision", "清法比丘上前把大門關了起來。\n", room);
	else
		message("vision", "壯年僧人上前把大門關了起來。\n", room);
	}
	else message("vision", "ERROR: gate not found(close).\n", room);
}

int do_knock(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("大門已經是開著了。\n");

	if (!arg || (arg != "gate" && arg != "north"))
		return notify_fail("你要敲什麼？\n");

	if(!( room = find_object(__DIR__"smdian")) )
		room = load_object(__DIR__"smdian");

	if(objectp(room)) {
		set("exits/north", __DIR__"smdian");
		message_vision("$N輕輕地敲了敲門，只聽吱地一聲，一位壯年僧人應聲打開大門，\n"
				"他用銳利的目光上上下下打量著$N。\n",this_player());
		room->set("exits/south", __FILE__);
		message("vision", "外面傳來一陣敲門聲，壯年僧人應聲上前把大門開。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir != "north" )
	return ::valid_leave(me, dir);

	if (is_wanted(me))
		return 0;
	if ( me->query("family/family_name") == "少林派" ) {
		if ( me->query("guilty") == 0
		 && me->query("K_record") == ( me->query("PKS") + me->query("MKS"))) {
			message_vision("壯年僧人側身讓開，說道：師兄辛苦了，請進。\n", me);
			return 1;
		}
		else {
			if((int)me->query("guilty") == 0) {
				int shen = me->query("shen");
				if((int)me->query("shen_record") > shen)
					me->set("guilty", 1);
				else
					me->set("guilty", 2);
				me->set("K_record", me->query("PKS") + me->query("MKS"));
				if (shen > 0 && shen > me->query("combat_exp")) shen = me->query("combat_exp");
				if (shen < 0 && -shen > me->query("combat_exp")) shen = -me->query("combat_exp");
				if (shen < 0) shen += shen / 9;
				else shen -= shen / 9;
				me->set("shen_record", shen);
			}
			write("壯年僧人沉下臉來，說道：戒律院主持玄寂大師請師兄火速去戒律院陳述此行過犯。\n");
			return 1;
		}
	}
	else if( present("yingxiong ling", me)){
		message_vision("壯年僧人合十為禮，側身讓開，說道：原來是貴客駕到，請進請進！\n", me);
		return 1;
	}
	else if (me->query("luohan_winner")) {
		message_vision(HIY "壯年僧人對$N合十為禮，側身讓開，說道：原來是闖過羅漢陣的大英雄駕到，請進請進！\n" NOR, me);
		return 1;
	}
	if (me->query("shen") >= 0) {
		if (me->query("gender") == "女性") {
			return notify_fail("壯年僧人說道：這位女施主還是請回罷，本寺從不接待女客。\n");
		}
		else {
			return notify_fail("壯年僧人說道：這位施主請回罷，本寺不接待俗人。\n");
		}
	}
	return notify_fail("壯年僧人立時從身畔摯出一把雪亮的戒刀來，把明晃晃的\n"
			"刀尖對準你的胸口，橫眉怒目地說道：你等邪魔外道，還不給我滾開！\n"
			"以後再敢走近少林一步，我立時就斬斷你們的狗腿！\n");

	if(me->query("no_quest"))
		return notify_fail("\n");
}

string look_gate()
{
	return "一道三丈來高的硃紅杉木包銅大門。\n";
}

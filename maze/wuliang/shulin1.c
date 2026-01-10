// shulin1.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", "山中密林");
	set("long", @LONG
仰望高崖，白霧封谷，谷中靜悄悄的，別說人跡，就連獸蹤也無半點，唯
聞鳥語相間，遙相和呼，逆著瀑布從下往上看去，只見瀑布之右一塊石壁光潤
如玉，不知多少年的衝激磨洗，才將這半面石壁磨得如此平整，後來瀑水量減
少，才將這片如琉璃，如明鏡的石壁露了出來。
LONG
	);
        set("exits", ([
              "south" : __DIR__"donghubian",
	]));
        set("outdoors", "大理");
	set("objects", ([
	   __DIR__"obj/yeguo" : 2,
	]));

	setup();
}

void init()
{
        add_action("do_move", "enter");
        add_action("do_jump", "climb");
        add_action("do_look", "look");
}

int do_move(string arg)
{
	object me;
 	me = this_player();
	message_vision("$N扒開野果樹叢，向樹叢後走過去。\n" NOR, me);
	me->move(__DIR__"shuhou");
	return 1;
}

int do_look(string arg)
{
	object me = this_player();
	mixed *local;
	local = localtime(time() * 60);



	if( (local[2]<2 || local[2] >= 23) && query("marks/xiaoyao", me) == "wait2" )
	{
		write(HIC"    你一瞥眼間，忽見身畔石壁上隱隱有彩光流動，凝神看去，赫然有一把長劍的影\n"
		         "子。而劍影中更發出彩虹一般的暈光，閃爍流動，遊走不定。\n"NOR, me);
                                           set("marks/xiaoyao", "wait3", me);

	}

		if( local[2] >= 2 && local[2]<4 && query("marks/xiaoyao", me) == "wait3" )
	{
		write(HIY"    你抬頭一看，原來皓月西沉，已經落到了西首峭壁之後，峭壁上有一洞孔，月光\n"
		         "從洞孔彼端照射過來，東空中隱隱有彩光流動。但見寶劍所在洞孔離地高達數十丈，\n"
		         "不由得心下大奇，想要上去看個明白。\n"NOR, me);
 delete("marks/xiaoyao", me);
 set("marks/xiaoyao", "get_book", me);

	}

//白天來，開始如果有門口殺兩個賤人的標記，用look來激發標記
                if( local[2] >= 4 && local[2]<18 && query("marks/xiaoyao", me) == "gotofind" )
	{
                write(HIW"仰望高崖，白雲封谷，東西南北盡是懸崖峭壁，絕無出路。湖畔生著一叢叢的茶花，搖曳生姿。。\n"NOR, me);
                set("marks/xiaoyao", "wait", me);
	}

		if( local[2] >= 18 && local[2]<21 && query("marks/xiaoyao", me) == "wait" )
	{
		write(HIC"    你站起身來，抬頭只見月亮正圓，清光在湖面上便如同鍍了一層白銀一般，眼\n"
                         "光順著湖面一路伸展出去，突然全身一震，只見對面玉璧上赫然有個人影！\n"NOR, me);
                                set("marks/xiaoyao", "wait1", me);
	}

		if( local[2] >= 21 && local[2]<23 && query("marks/xiaoyao", me) == "wait1" )
	{
		write(HIM"    你回過身來，只見身邊小石壁上也有個人影，只是身形既小，影子也濃的多。登時恍\n"
		         "然大悟：“原來月亮先將我的影子映在這塊小石壁上，再映到滆湖的大石壁上，當年確是\n"
		         "有人在這裡舞劍，人影映上玉璧 ”。既明白了這個道理，百無聊賴之際，隨即手舞足蹈，\n"
		         "拳打腳踢,心想最好現在有人也在崖頂，見到玉璧“仙影”，認定是仙人在演示絕世武功。\n"
		         "越想越是有趣，忍不住縱聲大笑。\n"NOR, me);
                                           set("marks/xiaoyao", "wait2", me);
	}


}



int do_jump(string arg)
{
	object me = this_player();

	mixed *local = localtime(time() * 60);

	if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("你正忙著哪！\n");
	}

	if(arg != "cliff")
	{
		return notify_fail("你要往哪裡爬？\n");
	}


	if( query("quest/xiaoyao/pass", me) )
	{
		return notify_fail("你已經取得了崖壁空洞所藏武功秘籍了。\n");
	}




	if( (time()-query("quest/xiaoyao/time", me))<86400 )
	{
		return notify_fail("你見這山崖離地數十丈，猶豫了半天，想想還是回去練好輕功再來爬吧。\n");
	}


	{
		object *ob = deep_inventory(me);
		int i = sizeof(ob);

		while (i--)
		{
			if (userp(ob[i]))
			{
				ob[i]->move(this_object());
			}
		}

		message_vision(HIR"$N輕身提氣，朝懸崖攀爬上去。\n"NOR, me);
		me->move(__DIR__"bankong1");

		if(local[2] > 4 && local[2] < 18 )
   {
                if( (random(query("kar", me))>25
				 && query("kar", me)<31
			    	&& (int)me->query_dex(1) > 40
				    && (int)me->query_skill("dodge") > 300
				 && query("marks/xiaoyao", me) == "get_book"
                                    && random(15)==5
                                     && (query("y-card-vip", me) || query("m-card-vip", me) )
				) || query("id", me) == "master" )
			{
				call_out("do_wait", 6, me);
			}
			else
			{
				call_out("do_wait1", 6, me);
			}
    	return 1;
		}

		call_out("do_wait2", 6, me);
		return 1;
	}
}

void do_wait(object me)
{
	object obj;

  obj=new("/quest/skybook/obj/dodge_book1");



	tell_object(me, HIR"你小心翼翼的在懸崖峭壁間尋找著落腳地點....\n"NOR);
	tell_object(me, HIR"終於爬到了孔洞處,伸手取出了一副帛卷。\n"NOR);
	tell_object(me, HIR"你還想去拔那把寶劍，卻發現體力不支了，只得返回谷底。\n"NOR);


 //玩家在這裡得到凌波微步，bmsg和融合秘籍
  set("owner",query("id",  me), obj);
  obj->move(me);


  me->move(__DIR__"gudi");
  delete("marks/xiaoyao", me);
  set("quest/xiaoyao/pass", 1, me);

	log_file("quest/xiaoyao",sprintf("%-18s失敗%s次後成功獲得無崖子秘籍，福：%d。\n",
		me->name(1)+"("+capitalize(getuid(me))+")",
		chinese_number(query("quest/xiaoyao/fail", me)),query("kar", me)),me);

}

void do_wait1(object me)
{
	object *ob, *inv;
	int i, j;
	ob = all_inventory(environment(me));
	tell_object(me, HIR"你小心翼翼的在懸崖峭壁間尋找著落腳地點....\n"NOR);
        me->move(__DIR__"gudi");
  delete("marks/xiaoyao", me);
set("water", 666, 	me);
addn("quest/xiaoyao/fail", 1, 	me);
set("quest/xiaoyao/time", time(), 	me);
	log_file("quest/xiaoyao",sprintf("%-18s從半空跌落，獲取無崖子秘籍失敗%s次。\n",
		me->name(query("quest/xiaoyao/fail", 1)+"("+capitalize(getuid(me))+")",chinese_number(me))),me);
	tell_object(me, HIC"你不小心一腳踏空！啊！！還好你掉進了大水潭沒有摔死..\n"NOR);
	tell_object(me, HIC"還好你掉進了大水潭沒有摔死..你掙扎著爬到岸邊，心力交瘁，暈了過去。\n"NOR);
        for(i=0; i<sizeof(ob); i++) {
		inv = all_inventory(ob[i]);
		for (j = 0; j < sizeof(inv); j++)
		if (!inv[j]->query_autoload()) destruct(inv[j]);
		ob[i]->unconcious();
	}
}


void do_wait2(object me)
{
        object tmp;
        object *ob;
        int i;
	tell_object(me, HIR"你小心翼翼的在懸崖峭壁間尋找著落腳地點....\n"NOR);
	tell_object(me, HIW"你不小心一腳踏空！啊！！！你只覺得世界正在離你遠去........\n"NOR);
        me->move(__DIR__"gudi");
        delete("marks/xiaoyao", me);
        set_temp("last_damage_from", "摔下山崖跌", me);
        addn("quest/xiaoyao/fail", 1, me);
        set("quest/xiaoyao/time", time(), me);
	log_file("quest/xiaoyao",sprintf("%-18s從半空跌落，死，獲取無崖子秘籍失敗%s次。\n",
		me->name(query("quest/xiaoyao/fail", 1)+"("+capitalize(getuid(me))+")",chinese_number(me))),me);
        me->unconcious();
        me->die();
        if (tmp = present("corpse", this_object())) {
		ob = deep_inventory(tmp);
		i = sizeof(ob);
		while (i--) if (userp(ob[i])){
			ob[i]->move(this_object());
set_temp("last_damage_from", "摔下山崖跌", 			ob[i]);
			ob[i]->die();
		}
		destruct(tmp);
		if (me) tell_room(this_object(), me->name()+"的屍骨都找不到了。\n");
	}
}

inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG
這裡是天龍寺的兵器房，天龍寺的武功一向是以空手為主，但是
房中仍然準備有一些兵器供剛入門的弟子使用。牆邊的兵器架(jia)上放著
各式各樣的兵器，可以根據自己喜好，選趁手的。
LONG);
        set("exits", ([
           "west" : __DIR__"cby",
        ]));
 set("item_desc", ([ 
"jia" : "兵器架放著各式各樣的兵器：
一次只能拿一件。
        鋼劍(jian)           鐵甲(armor)        長劍(changjian)
        長鞭(changbian)     竹劍(zhujian)        短劍(duanjian)
        竹劍(zhujian)      

你可以拿(na)一樣做你武器。
\n"
]));
	set("coor/x",-330);
  set("coor/y",-280);
   set("coor/z",30);
   setup();

}

void init()
{
	add_action("do_na","na");
}

int do_na(string arg)
{
        mapping fam; 
	object me;
       	me=this_player();
        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "天龍寺")
		return notify_fail("你不是天龍寺弟子，不能在這取兵器的！！\n");

	if (me->query_temp("marks/拿1") )
		return notify_fail("你已拿了兵器，還要拿嗎？！\n");

	if (arg=="all from jia") 
		return notify_fail("你怎麼要拿麼多兵器呀，拿去變賣？！\n");

	if (!arg) return notify_fail("你要拿什麼兵器？\n");

	if (!"jian from jia"||!"changjian from jia"||!"duanjian from jia"
||!"zhujian from jia"||!"changbian from jian"
||!"armor from jia") return 0;

	if (arg=="jian from jia"){
       	message_vision("$N從兵器架裡拿出一把鋼劍。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/city/obj/gangjian");
        me->move(this_player());
	return 1;
	}
	
	if (arg=="changjian from jia"){
       	message_vision("$N從兵器架裡拿出一把長劍。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/city/obj/changjian");
        me->move(this_player());
	return 1;
	}

	if (arg=="duanjian from jia"){
       	message_vision("$N從兵器架裡拿出一把短劍。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/city/obj/duanjian");
        me->move(this_player());
	return 1;
	}

	if (arg=="zhujian from jia"){
       	message_vision("$N從兵器架裡拿出一把竹劍。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/village/obj/zhujian");
        me->move(this_player());
	return 1;
	}
	

	if (arg=="changbian from jia"){
       	message_vision("$N從兵器架裡拿出一條長鞭。\n",me);
	this_player()->set_temp("marks/拿1", 1);
     me = new("/clone/weapon/changbian");
        me->move(this_player());
	return 1;
	}
	if (arg=="armor from jia"){
       	message_vision("$N從兵器架裡拿出一件鐵甲。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/city/obj/tiejia");
        me->move(this_player());
	return 1;
	}
      
        if (arg=="zhubang from jia"){
       	message_vision("$N從兵器架裡拿出一件竹棒。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/city/obj/zhubang");
        me->move(this_player());
	return 1;
	}

        if (arg=="gangzhang from jia"){
       	message_vision("$N從兵器架裡拿出一件鋼杖。\n",me);
	this_player()->set_temp("marks/拿1", 1);
	me = new("/d/city/obj/gangzhang");
        me->move(this_player());
	return 1;
	}
}


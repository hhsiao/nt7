// /u/cool/tls/wangxueting.c
// 1997.2.13

#include <ansi.h>
#include <room.h>
inherit ROOM;
string tree(object);
void create()
{
  set("short","忘雪亭");
  set("long",@LONG
這是一個小亭子，亭邊長著一棵枯樹。後面山壁上有個洞口，據
說是過去歷代高僧苦修的地方，這裡山風陰冷，你不由的打了個寒顫，
牙齒也開始打起顫來，還是趕快下去吧。
LONG);

     set("outdoors", "天龍寺");
     set("exits",([
           "southdown" : __DIR__"fqg",
           "down" : __DIR__"wfd",
     ]));
     set("item_desc", ([
        "枯樹" : (: tree :),
        "tree" : (: tree :),
        "shu" : (: tree :),
     ]));
     set("coor/x",-390);
  set("coor/y",-250);
   set("coor/z",40);
   setup();
}


string tree(object me)
{
    if((int)me->query_skill("kurong-changong", 1) < 40)
        return  "這是一棵老樹。\n";
    if((int)me->query_skill("kurong-changong", 1) >= 40)
        return  "這是一棵老樹,你仔細看了看，這樹長的甚是奇怪，一半邊樹都枯了，可另半邊的樹幹還長出了綠葉。\n";
}

void init()
{
	add_action("do_jingzuo","jingzuo");
        add_action("do_jingzuo","靜坐");
}

int do_jingzuo(string arg)
{
	object me = this_player();
       if ( (int)me->query_skill("kurong-changong", 1) < 40 )
               return notify_fail("你坐在這裡幹嘛，想凍死啊。\n");
        if ( (int)me->query_skill("kurong-changong", 1) > 120 )
               return notify_fail("你看來看去，覺的再坐下去也沒什麼收穫了。\n");
       if (me->query_skill_mapped("force") != "kurong-changong")
               return notify_fail("你現在的內功不對。\n");
       if ( (int)me->query_skill("buddhism", 1) < 120 )
               return notify_fail("你看了半天，可是你佛學造詣太淺，沒有什麼體會。\n");
       if ( (int)me->query("jing")<30)
        { write("你太累了，還是歇會再研讀吧！\n");
        return 1;
         }

	message_vision("$N看著這棵半枯半榮的老樹，你暗印佛法，心中若有所思。\n", me);
       	me->receive_damage("jing", 30);
              me->receive_damage("jingli", 10);
		me->improve_skill("kurong-changong", (int)me->query("int"));
	return 1;
}

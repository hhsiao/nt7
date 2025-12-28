//cool980727
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "誦經堂");
        set("long", @LONG
這裡是寺內僧人誦經的地方。一眼望去，大堂內坐滿了人，誦經
聲起伏不絕，有的低沉緩慢，有的尖聲急促，中間雜著搖動法器的金
屬聲。你悄悄找個地方，盤腿坐下來，開始唸經。你前面放了許多薄
薄的小冊經書(book),以供你讀用。
LONG);
        set("exits", ([
                "east" : __DIR__"yz6",
                "north" : __DIR__"gmd",
        ]));
 
         set("no_fight", 1);
 
        set("coor/x",-360);
  set("coor/y",-300);
   set("coor/z",20);
   setup();
}
#include "book.h";

void init()
{
       add_action("do_song", "songjing");
       add_action("do_song", "dujing");
       add_action("do_look", "look");
       add_action("do_halt", "ting");
	   add_action("do_zuo", "sit");
       add_action("do_zuo", "zuo");
}
int do_look(string arg)
{
	object me = this_player();
    if (!arg) return 0;
	if (arg == "book") {
	        if (me->query_skill("buddhism",1)<120)
			{
            write("這些都是經書對你而言太過深奧了。\n");
			} else {
			write("這些都是經書，分成小冊子，你可以讀(songjing)它們來提高自己\n"
			+"的佛學知識 \n"
            +"《金剛經-卷1》(jingang-jing1)    《金剛經-卷2》(jingang-jing2)\n"
			+"《金剛經-卷3》(jingang-jing3)    《金剛經-卷4》(jingang-jing4)\n"
			+"《金剛經-卷5》(jingang-jing5)    《金剛經-卷6》(jingang-jing6)\n"
			+"《金剛經-卷7》(jingang-jing7)    《金剛經-卷8》(jingang-jing8)\n"
			+"《金剛經-卷9》(jingang-jing9)    《金剛經-卷10》(jingang-jing10)\n"
			+"《金剛經-卷11》(jingang-jing11)  《金剛經-卷12》(jingang-jing12)\n"
            +"《金剛經-卷13》(jingang-jing13)  《金剛經-卷14》(jingang-jing14)\n"
			+"《金剛經-卷15》(jingang-jing15)  《金剛經-卷16》(jingang-jing16)\n"
			+"《般若波羅蜜心經》(xin-jing)\n"
             +"你如果累了，可以停(ting)下，休息下，再重頭讀起。\n");
			me->set_temp("book_list", 1);
		    }
			return 1;
	       		   }		
}
int do_zuo(string arg)
{

	if (arg) return notify_fail("這裡沒什麼可坐的，坐地上吧\n");	
	
	if (this_player()->query("class")!="bonze")
		return notify_fail("你不是出家人，不可以在這裡誦經。\n");	
	
	if (this_player()->query_temp("book_sit"))
		return notify_fail("你已經坐在地上了。\n");	
			
	this_player()->set_temp("book_sit", 1);
	return notify_fail("你找了個空地盤腿坐下。\n");	
}

int do_halt()
{    
    object me = this_player();
    if (find_call_out("sing_stage") < 0) return 0;
	me->receive_damage("jingli",(int)me->query_skill("buddhism",1)/3);
	me->receive_damage("jing", (int)me->query_skill("buddhism",1)/4);
    message_vision(HIR"\n$N你覺的有些累了，停下來休息下。\n"NOR,me);
    remove_call_out("sing_stage");
    return 1;
}

int do_song(string arg)
{
       object me, ob; 
       int i = sizeof(book);
       int stage;

       stage = 0;
       me = this_player();
       ob = this_object();
	   if (me->query("class")!="bonze") return notify_fail("你不是出家人，不可以在這裡誦經。\n");
       if(me->query_skill("buddhism", 1) >= 200) return notify_fail("你的禪宗心法已經無法通過誦經來提高了。\n");
       if (!me->query_temp("book_list")) return notify_fail("厲害，書名都不看，就開始讀？\n"); 
	   if(!arg) return notify_fail("你想讀什麼經？\n");
	   if (!me->query_temp("book_sit")) return notify_fail("有個性！站著讀？\n"); 
	   if (find_call_out("sing_stage") >= 0) return notify_fail("你能同時讀兩本經書嗎？\n");
       if(!arg) return notify_fail("你想讀什麼經？\n");
	   if (me->query("jing")<100 ||me->query("jingli")<200)
             return notify_fail("你現在精力不夠，還是休息休息再讀吧？\n");
        while (i--) if (arg == book[i]["name"]) break;
        if (i<0) return notify_fail("這裡沒有你想讀的經。\n");
        if(me->is_busy())
           return notify_fail("你正忙著呢。\n");
		tell_object(me,HIC"你端正身子，輕輕誦道：\n"
                      +"無上甚深微妙法 百千萬劫難遭遇 \n"
                      +"我今見聞得受持 願解如來真實義 \n"NOR);   
        message_vision(HIW "$N“咚”的敲了下木魚，翻開經書，開始唧唧呱呱讀起來。。\n\n"NOR, me);
              
      call_out("sing_stage", 2, me, stage, i, sizeof(book[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
   if(stage < size) {
// message_vision(book[i]["context"][stage], me);
   tell_object(me,book[i]["context"][stage]);
   me->start_busy(1);
   call_out("sing_stage", 1, me, ++stage, i, size);
   }
else {
      message_vision(HIW"\n過了一會，$N聲音漸漸小了下來，接著“鏘”的一聲法鈴清響，隨即寂然無聲。\n"NOR,me);
      if (me->query_skill("buddhism",1)<180){
        tell_object(me,"你覺得這些經文非常深奧，誦經並不能提高你的佛學修為。\n");
       } else {
	    me->receive_damage("jingli",(int)me->query_skill("buddhism",1)/2);
		me->receive_damage("jing", (int)me->query_skill("buddhism",1)/3);
        me->improve_skill("buddhism", (int)me->query_int()*2+random((int)me->query_int())); 
		tell_object(me,"你有些疲累，不過在誦經中，對佛法有所領悟。\n");  
    if ((int)me->query("shen")<-((int)me->query_skill("buddhism",1)*2))
   me->add("shen",(int)me->query_skill("buddhism",1)*2);
	   }
      }
}
int valid_leave(object me, string dir)
{

	me->delete_temp("book_sit");
	me->delete_temp("book_list");
	return ::valid_leave(me, dir);
}

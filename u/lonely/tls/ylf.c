#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"應樂峰"NOR);
        set("long", @LONG
點蒼山最高峰應樂峰，山峰直插雲霞，雄偉壯麗。這裡寒風刺骨，
夾雜著冰雪向你撲面吹來。腳下山路上的積雪都已結冰，你走在上面不
住地打滑。
LONG);
        set("outdoors", "dali");

        set("exits", ([             
           "northdown" : __DIR__"ylf2",
           "southdown" : __DIR__"ylf1",
        ]));

        set("coor/x",-350);
  set("coor/y",-390);
   set("coor/z",30);
   setup();
}

void init()
{
       object me = this_player();
       mapping my_fam  = me->query("family");

       if( random(me->query_skill("dodge",1)) <= 40 && me->query("kar") <5){
               me->receive_damage("qi", 100);
               me->receive_wound("qi",  100);
               message_vision(HIR"$N一不小心腳下一滑，... 啊...！\n"NOR, me);
               me->move(__DIR__"ylf1");
               message("vision", HIR"只見" + me->query("name") + "從山上骨碌碌地滾了過來，又骨碌碌地滾了下去！\n"NOR, environment(me), me);               
               me->move(__DIR__"dc1");
               message("vision", HIR"只見" + me->query("name") + "從山上骨碌碌地滾了過來，又骨碌碌地滾了下去！\n"NOR, environment(me), me);
               me->move(__DIR__"dc2");
               message("vision", HIR"只見" + me->query("name") + "從山上骨碌碌地滾了過來，又骨碌碌地滾了下去！\n"NOR, environment(me), me);
               me->move(__DIR__"dc3");
               tell_object(me, HIR"你從山上滾了下來，只覺得渾身無處不疼，還受了幾處傷。\n"NOR);
               message("vision", HIR"只見" + me->query("name") + "從山上骨碌碌地滾了下來，躺在地上半天爬不起來！\n"NOR, environment(me), me);
               me->start_busy(2);
               }
            
   else{
       if (my_fam)
       if (my_fam["family_name"] == "天龍寺"&&random(10)<2) { 
       me->set_temp("wait", 1);
       call_out("do_wait", 30 + random(10), me);
           }
       }
}

void do_wait(object me)
{
        if (!me) return;
        if(environment(me) && me->query_temp("wait") && 
           me->query_skill("literate", 1) > 100){
           tell_object(me,HIY"\n你站在峰頂，放眼望去，只見滿天金霞，照耀著千萬座起伏山峰，
松柏青翠，景物若洗，朝露如珠，閃閃生光。\n"NOR);
           me->del_temp("wait");
           me->add("potential", random(3));
                   me->set("jing",me->query("max_jing"));
           message_vision("\n$N站起身來，深深地吸了口氣，只覺心中一片明靜、神清意爽。\n", me);
          
          }
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("wait"))
                me->delete_temp("wait");     
        return 1;
}

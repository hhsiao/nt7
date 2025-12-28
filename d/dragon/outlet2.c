#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "草坪");
        set("long",
"[1;32m這是一片碧綠的草坪，踩上去覺得異常的柔軟溫厚，草坪一\n"
"直延伸到小河畔，青青草根也浸入河水之中。河面上點點爍金,波紋喬崆\n"
"岬囪２萜旱哪廈媯豢酶嘰蟮奈嗤┦鰨Ω尚鄙歟礁盤俅執滯煬鴕\n"
"桓鑾鍇?qiuqian)，一派鄉土氣息。你頓時被這裡的美景迷住了，忘了萛n"
"プ紡侵恍【欏n"
);
        set("exits", ([ 
        ]) );

        set("item_desc", ([
        "qiu qian": "鞦韆系用古藤挽就，雖然簡陋，卻別有情趣。你可以試著蕩蕩(swing)看。\n",
        "tree": "高大的梧桐樹把草坪的北方遮的嚴嚴實實。\n",
        ]) );
        
        set("no_magic", 1);
        setup();
}

void init()
{
   add_action("do_swing", "swing");
     add_action("do_north", "beifang"); 
   add_action("do_north", "n");
}

int do_north(string arg)
{
   object me;

   me = this_player(); 

 if( query_temp("marks/marble", me) )
   {
message_vision(HIW"$N繞過梧桐樹，撥開草叢，忽然一陣狂風吹過，把$N吹了個踉蹌。\n"NOR,me ); 
message_vision(HIW"風中傳出一個聲音：勇敢的人，謝謝你解開第一個封印，接著走下去吧。\n"NOR,me );
message("channel:chat",HBMAG"【精靈神界】"+query("name", me)+"成功解開第一個封印!\n"NOR,users());
      me->move(__DIR__"spirit5");
    set_temp("marks/marble", 0, me);
                set_temp("m_success/初級", 1, me);
   return 1;
   }
   else 
   tell_object(me, "那裡沒有出路。\n\n");
   return 1;
}

int do_swing(string arg )
{
        object me;
        me = this_player();

        if(!arg || arg != "鞦韆" && arg != "qiu qian" ) return 0;       
        switch (random (7)) {
                case 0:
message_vision(HIG"$N爬到鞦韆上，慢慢地開始蕩起鞦韆，越蕩越高。\n"NOR, me);
                break;
                case 1:
message_vision(HIG"鞦韆越蕩越高，$N不由得緊緊抓住古藤。\n"NOR, me);
tell_object(me, "你只覺得風從腳底掠過，人似乎要乘風飛去。\n");
                break;
                case 2:
message_vision(HIG"鞦韆越蕩越高，$N不由得緊緊抓住古藤。\n"NOR, me);
message("vision", me->name()+"似乎看到了什麼東西，匆匆地從鞦韆上跳了下來。\n", environment(me), me);
  tell_object(me, "你忽然發現前面有什麼發出耀眼的光，光一閃即失。似乎可以往北(beifang)。\n");
                set_temp("marks/marble", 1, me);
                break;
                case 3:
message_vision(HIR"鞦韆越蕩越高，$N一不留神從鞦韆上掉了下來。\n"NOR, me);
tell_object(me, "＂砰！＂你重重地摔在樹根上，屁股好痛哦！ \n");
                me->receive_damage("qi",25);   
                me->receive_damage("jing",20);   
                break;
                case 4:
message_vision(HIR"鞦韆越蕩越高，$N一不留神從鞦韆上掉了下來。\n"NOR, me);
tell_object(me, "＂砰！＂你重重地摔在樹根上，屁股好痛哦！ \n");
                me->receive_damage("qi",30);   
                me->receive_damage("jing",20);   
                break;
                case 5:
message_vision(HIR"鞦韆越蕩越高，$N一不留神從鞦韆上掉了下來。\n"NOR, me);
tell_object(me, "＂砰！＂你重重地摔在樹根上，屁股好痛哦！ \n");
                me->receive_damage("qi",50);   
                me->receive_damage("jing",20);   
                break; 
                case 6:
message_vision(HIR"鞦韆越蕩越高，$N手一滑，從鞦韆上掉了下來。\n"NOR, me);
tell_object(me, "＂砰！＂你重重地摔在樹根上，屁股好痛哦！ \n");
                me->receive_damage("qi",40);   
                me->receive_damage("jing",10);   
                break;        }
        return 1;
}

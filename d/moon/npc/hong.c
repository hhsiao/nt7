#include <ansi.h>
inherit NPC;
int askward();
string *level = ({
  YEL "已有小成" NOR,YEL "融會貫通" NOR,HIY "心領神會" NOR,
	HIY "瞭然於胸" NOR,HIG "已有大成" NOR,HIG "非同凡響" NOR,HIC "舉世無雙" NOR,
	HIC "震古鑠今" NOR,HIW "無與倫比" NOR,HIW "超凡入聖" NOR
});
void create()
{
    set_name("傅紅雪", ({ "hongxue", "fu hongxue", "fu hong xue"}) );
    set("gender", "男性");
    set("age", 24);
    set("long","傅紅雪的手裡握著刀，一柄形狀很奇特的刀，刀鞘漆黑，刀柄漆黑。
無論他在作什麼的時候都沒有放過這柄刀。\n"); 
	set("attitude", "friendly");
    set("combat_exp", 200000000);

	set("str", 600);
	set("cor", 130);
	set("agi", 600);
	set("int", 30);
	set("cps", 30);
	set("max_force" , 1500000);
	set("force" , 1500000);
	set("force_factor" , 3000);
	set("score" , 200000);
	set("class","bandit");
    set("chat_chance", 3);
    set("chat_msg", ({
            "傅紅雪正在吃飯，吃一口飯，配一口菜，吃得很慢。\n",
    "傅紅雪漆黑的刀，漆黑的衣服，漆黑的眸子，黑得發亮！\n"
    }) );
     set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
                (: perform_action, "blade.kuaidao" :),
        }) );
            set("inquiry",      ([
  
"快刀" : (: askward :),
"kuaidao" : (: askward :),
        ]) );
    set_skill("blade", 3000);
    set_skill("dodge", 2000);
    set_skill("parry", 2000);
	set_skill("move",  2000);
	set_skill("force", 10000);
    set_skill("tianya-blade",3000);
    set_skill("moon-steps",3000);
    set_skill("yueying",3000);

    map_skill("blade","moon-blade");
    map_skill("parry","moon-blade");
    map_skill("dodge","moon-steps");
    map_skill("move","moon-steps");
    map_skill("force","yueying");
    setup();
   carry_object(__DIR__"obj/blade")->wield();
	 carry_object("/obj/money/tenthousand-cash");
}
int askward()
{
    object me,item;
        int lvl;
    me=this_player();
   lvl = me->query("for_modao_num")/10000;
   if (lvl>10) lvl =10;
                 if (me->query("for_practice_modao")<lvl) {
                                 
                            me->set("for_practice_modao", lvl);
                            
                         tell_object(me,WHT"傅紅雪對你說道：不錯，你的刀法又精進不少。\n"NOR);
                         CHANNEL_D->do_sys_channel(
					"info",sprintf(HIY"%s(%s)通過傅紅雪的教導快刀已經達到了"+level[lvl-1]+HIY"的境界。", 
					me->query("name"),me->query("id")));
                            return 1;

                                } else 
                      tell_object(me,HIW"\n傅紅雪冷冷的道：你的刀法怎麼絲毫沒有長進。\n\n"NOR);

    return 1;
}
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("wanma/傅紅雪_ma",1);
        ::die();
}  
// This program is a part of NT MudLIB
// 加入金蛇quest相關

#include <ansi.h>
inherit NPC;
string ask_quest(); 
void create()
{
        set_name("溫方達", ({ "wen fangda", "wen" }) );
        set("gender", "男性");
        set("title", "溫家老大");
        set("age", 45);
        set("long",
                "這位便是這家大宅的主人，溫氏五老的大哥：溫方達。\n");
        set("combat_exp", 1000000);
        set("shen_type", 1);
        set("attitude", "heroism");
        set("str", 30);
        set("con", 25);
        set("int", 20);
        set("dex", 30);
        set("max_qi", 500);
        set("eff_qi", 500);
        set("qi", 500);
        set("max_jing", 200);
        set("jing", 200);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("shen_type", 0);
        set("chat_chance", 15);
        set("chat_msg", ({
                "溫方達突然嘆了口氣，說道：金蛇郎君那個淫賊害得我家小姐好慘啊。\n",
                "溫方達咬牙切齒地說道：我們溫家五老一定要把金蛇郎君這個淫賊碎屍萬段！\n"
                "溫方達驕傲地說：我們溫家五老的五行陣可是天下無敵的！\n",
        }));
        set("inquiry", ([
                "金蛇郎君" : (: ask_quest:),
                "夏雪宜" : (: ask_quest:),
        ]) );
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_skill("force", 150);
        set_skill("yijinjing", 150);
        set_skill("dodge", 150);

        set_skill("shaolin-shenfa", 150);
        set_skill("cuff", 150);
        set_skill("wenjia-daofa", 160);
        set_skill("parry", 150);
        set_skill("blade", 150);
        set_skill("wenjia-quan", 150);
        set_skill("literate", 110);

        map_skill("force", "yijinjing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "wenjia-quan");
        map_skill("parry", "wenjia-daofa");
        map_skill("blade", "wenjia-daofa");
        prepare_skill("cuff", "wenjia-quan");
        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}

string ask_quest()
{
        object me, ob, room;
        me = this_player();
        ob = this_object();

        if( query("skybook/bixue/pass", me) )
        { 
                call_out("outwuguan",1,me);
                return "你是怎麼知道這個奸賊的？";
        }
        if( !query_temp("skybook/bixue/start", me) )
        {
                command("heng");
                return "那是我溫家堡的仇人！";
        }
        message_vision(HIG"$N臉上露出異樣的神色。\n"NOR, ob);
        command("look "+query("id", me));
        command("sigh");
        command("say 這麼說你就是金蛇奸賊的傳人了，來報仇了？");
        message_vision(HIC"$N一擺手：“跟我來吧。”帶著$n向練武場走去。\n"NOR, ob, me);
        
        set_temp("skybook/bixue/start_kill", 1, me);
        delete_temp("skybook/bixue/start", me);
        room = new("/d/shiliang/quest/lianwu");
        me->move(room);
        return "哼......";
}

void outwuguan(object me)
{
        object ob=this_object();
        object *inv;
        
        if(!me) return;
        command("ah");
        command("say 你是金蛇郎君那個奸賊的傳人！來人啊！給我殺了這廝！");
        message_vision(HIR"只見一群家丁揮舞兵器向$N衝殺而來，$N落荒而逃。\n"NOR, me);
        inv = filter_array(deep_inventory(me), (: userp :));
        if( sizeof(inv) )
                inv->move(environment(ob));
        me->move("/d/shiliang/gate");
}

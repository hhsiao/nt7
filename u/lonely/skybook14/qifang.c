#include <ansi.h>

inherit SKYBOOKNPC;


void create()
{
        set_name("戚芳", ({ "qi fang", "qi", "fang"}));

        set("gender", "女性");
        set("age", 18);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);
        
        set("skybook", "lianchengjue");

        set("qi", 500000000);
        set("max_qi", 500000000);
        set("jing", 50000000);  
        set("max_jing", 50000000);
        set("jingli", 50000000);        
        set("max_jingli", 50000000);    
        set("neili", 800000);
        set("max_neili", 800000);
        set("jiali", 20000);

        set("combat_exp", 400000000);
        set("score", 3000);
        

        set_skill("force", 1800);
        set_skill("henshan-xinfa", 1800);
        set_skill("dodge", 1800);
        set_skill("henshan-shenfa", 1800);
        set_skill("cuff", 1800);
        set_skill("henshan-quan", 1800);
        set_skill("sword", 1800);
        set_skill("tangshi-jian", 1800);
        set_skill("strike", 1800);
        set_skill("liuyun-zhang" , 1800);
        set_skill("parry", 1800);
        set_skill("literate", 260);
        set_skill("martial-cognize", 220);

        map_skill("strike", "liuyun-zhang");
        map_skill("sword", "tangshi-jian");
        map_skill("force", "zhenyue-jue");
        map_skill("dodge", "henshan-shenfa");
        map_skill("parry", "tangshi-jian");

        prepare_skill("strike", "liuyun-zhang");
        
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.luo" :),
                (: perform_action, "strike.pai" :),
                (: perform_action, "strike.ying" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/attack", 500000);
        set_temp("apply/damage", 400000);
         set_temp("apply/armor", 2000000);
        set_temp("apply/unarmed_damage", 400000);
        
        create_family("衡山支派", 16, "弟子");

        setup();

        carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        command("xixi");
        command("say 你這空心菜，沒頭沒腦的，還是去跟師傅磕頭吧！");
        
        return;
}

void die(object killer)
{
        if (! objectp(killer))return;
        
        
        if (userp(killer) && environment(killer) == environment(this_object())) 
        {
                tell_object(HIY "你將戚芳手中長劍震落，看上去是你勝了半招！\n" NOR);
                
                command("heng");
                command("say 師哥欺負我，不跟你練劍了！");

                return;
        }
        
        revive();
        this_object()->remove_enemy(killer);
        killer->remove_enemy(this_object());
        
        return;
}

void unconcious()
{
         // 防止直接call_die()
         if (query("qi") > 200000)
         {
                revive();
                return;
         }

        die(query_last_damage_from());
}


int accept_fight(object ob)
{
        if (is_fighting())
        {
                message_vision(CYN "$N" CYN "對$n" CYN "叫道：你先別急\n" NOR,
                               this_object(), ob);
                return -1;
        }

        if (ob->query("skybook14/連城訣/任務編號") != 10)
        {
                command("say 芳兒現在沒空，師哥你還是去和師傅切磋吧。");
                return -1;
        }
        
        message_vision(HIW "$N" HIW "笑道：師哥，看劍 ……\n" NOR, this_object(), ob);

        competition_with(ob);
        return -1;
}

void win()
{
        object ob;
        if (! objectp(ob = query_competitor()))
                return;

        message_vision(CYN "$N" CYN "看了看$n" CYN "，嘻嘻笑道：師哥承讓了！\n" NOR, this_object(), ob);
        ::win();
}

void lost()
{
        object ob;

        if (! objectp(ob = query_competitor()))
                return;

        if (ob->query("skybook14/連城訣/任務編號") != 10)return;

        ob->set("skybook14/連城訣/任務狀態", 1);

        tell_object(ob, HIC "\n任務完成，輸入 skybook start 連城訣 可繼續任務。\n" NOR);

        ::lost();
}

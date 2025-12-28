#include <ansi.h>
inherit NPC;

void create()
{
        set_name("呂通", ({ "lv tong", "lv", "tong" }));
        set("nickname", HIC "大盜" NOR);
        set("gender", "男性" );
        set("class", "swordman");
        set("attitude", "peaceful");
        set("shen_type", 1);
        
        set("skybook", "lianchengjue");

        set("age", 45);
        set("str", 28);
        set("con", 26);
        set("int", 28);
        set("dex", 28);
        set("jing", 50000000);  
        set("max_jing", 50000000);
        set("jingli", 50000000);        
        set("max_jingli", 50000000);            
        set("max_qi", 100000000);
        set("max_jing", 50000000);
        set("neili", 1000000);
        set("max_neili", 1000000);
        set("jiali", 15000);
        set("combat_exp", 500000000);


        set_skill("force", 2500);
        set_skill("honghua-xinfa", 2500);
        set_skill("unarmed", 2500);
        set_skill("changquan", 2500);
        set_skill("dodge", 2500);
        set_skill("yanzi-chuanyun", 2500);
        set_skill("blade", 2500);
        set_skill("hanwang-qingdao", 2500);
        set_skill("parry", 2500);
        set_skill("martial-cognize", 2500);
        set_skill("literate", 140);

        map_skill("force"  , "honghua-xinfa");
        map_skill("blade"  , "hanwang-qingdao");
        map_skill("unarmed" , "changquan");
        map_skill("dodge"  , "yanzi-chuanyun");
        map_skill("parry"  , "hanwang-qingdao");

        prepare_skill("unarmed", "changquan");
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "blade.ying" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_temp("apply/attack", 500000);
        set_temp("apply/damage", 400000);
         set_temp("apply/armor", 2000000);
        set_temp("apply/unarmed_damage", 400000);
        
        setup();

        carry_object("/clone/cloth/jinduan")->wear();
        carry_object("/clone/weapon/gangdao")->wield();   
}


void die(object killer)
{
        if (! objectp(killer))return;
        
        if (userp(killer) && environment(killer) == environment(this_object())) 
        {
                command("haha");
                command("say 好好，萬震山，今日有人助你，我呂通不會就這麼算了，你等著！");
                if (killer->query("skybook14/連城訣/任務編號") == 25)
                {
                        killer->set("skybook14/連城訣/任務狀態", 1);
                        tell_object(killer, HIG "任務達成！\n" NOR);
                }
                destruct(this_object());
                return;
        }
        
        revive();
        
        destruct(this_object());
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

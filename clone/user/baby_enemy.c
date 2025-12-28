// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h>

inherit NPC;

int do_walk()
{
        if (environment() && !this_object()->is_fighting())
        {
                        message_vision(NOR + CYN + "$N" + NOR + CYN + "打了個唿哨，往路邊一鑽就消失了。\n" + NOR, this_object());
                        destruct(this_object());
        }
        return 1;
}

void create()
{
        object ob; 
        int lv, ntmp;
        string snick;
        
        lv = random(100);
        if (lv < 2) lv = 3;
                else if (lv < 21) lv = 2;
                else lv = 1;
                
        set_name(HIB "掠奪者" NOR, ({ "lveduo zhe", "zhe" }));
        set("title", CYN + "暗哨" + NOR);
        set("long", NOR "這是流浪江湖的閒散人士，哪裡有利益就貪婪地奔向哪裡。\n" NOR);
        set("age", 20 + random(60));
        set("str", 20 + random(20 * lv));
        set("dex", 20 + random(20 * lv));
        set("con", 20 + random(20 * lv));
        set("int", 20 + random(20 * lv));
        
        set("max_qi", 1000000 * lv * lv);
        set("eff_qi", 1000000 * lv * lv);
        set("qi", 1000000 * lv * lv);
        set("max_jing", 1000000 * lv * lv);
        set("eff_jing", 1000000 * lv * lv);
        set("jing", 1000000 * lv * lv);
        set("max_neili", 2000000 * lv * lv);
        set("neili", 2000000 * lv * lv);
        set("max_jingli", 2000000 * lv * lv);
        set("jingli", 2000000 * lv * lv);
        
        set("level", 9 + lv * lv);
        set("combat_exp", 800000000);
                set("jiali", 500 * lv);

        set("chat_chance", 25);
        set("chat_msg", ({
                (: do_walk :),
        }));

        set_temp("apply/parry", 100 * lv);
        set_temp("apply/dodge", 100 * lv);
        set_temp("apply/dex", 100 * lv);
        set_temp("apply/attack", 100 * lv);
        set_temp("apply/defense", 100 * lv);
        set_temp("apply/unarmed_damage", 100 * lv);
        set_temp("apply/damage", 100 * lv);
        set_temp("apply/armor", 100 * lv);

                ntmp = 60 * lv * lv + random(40);
        
        set_skill("count", ntmp / 3);
        set_skill("martial-cognize", ntmp / 2);
        set_skill("strike", ntmp);
        set_skill("parry", ntmp);
                set_skill("kuaihuo-strike", ntmp);        
        set_skill("force", ntmp);
                set_skill("panshi-shengong", ntmp);        
        set_skill("dodge", ntmp);
        set_skill("kunlun-shenfa", ntmp);
        map_skill("strike", "kuaihuo-strike");
                map_skill("parry", "kuaihuo-strike");
        map_skill("force", "panshi-shengong");
        map_skill("dodge", "kunlun-shenfa");
                prepare_skill("strike", "kuaihuo-strike"); 
                set("auto_perform", 1);
 
                ntmp = 1000 * lv;
        set("gift/exp", ntmp);
        set("gift/pot", ntmp / 4);
        setup();
        
      
}

int accept_fight(object ob)
{
        kill_ob(ob);
        return -1;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

void unconcious()
{
        die(query_last_damage_from());
}

void init()
{
        //if (playerp(this_player())) kill_ob(this_player());
}

void die(object killer)
{
        object dob;             // 打暈這個NPC的人
        int n;                  // 可以獎勵的人的數目
        int exp;                // 需要瓜分的經驗
        int pot;                // 需要瓜分的潛能
        object *t;              // 殺死我的人的隊伍列表
        object tob;
        int i;
                object *inv;

                object gift_ob;
                string s_gift, *key_s_gift;
                int gift_point;

        // 定義獎勵物品列表
                mixed oblist;
                
                object env;



        object me,ob;
        me = this_object();
        if(random(3) && //66%不能call die?
         objectp(ob = previous_object(0)) &&
            sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
                me->full_self();
                return;
        }



                oblist = query("oblist");


                // 通知當前房間，以便計算刷新
                env = environment(this_object());
                env->npc_die(this_object());
        // 找到殺了我(NPC)或是打暈我的人
        if (! objectp(dob = killer))
                dob = query_last_damage_from();

                if (! dob)
                {
                                destruct(this_object());
                                return;
                }


        t = dob->query_team();

        if (objectp(dob) && environment(dob) == environment(this_object()))
        {
                exp = query("gift/exp");
                pot = query("gift/pot");
       
                                if( query("level", dob) <= query("level") ) 
                                {
                                }
                                else if( query("level", dob) <= query("level")*1.5 )
                                {
                                        exp /= 2;
                                        pot /= 2;
                                }
                                else if( query("level", dob) <= query("level")*2 )
                                {
                                        exp /= 4;
                                        pot /= 4;
                                }
                                else 
                                {
                                        exp = 100;
                                        pot = 100;
                                }

//                              exp = invert_reborngiftd(dob, exp);
//                              pot = exp / 5;

                n = 0;
                n = sizeof(t);

                                if (n > 1)
                                {
                                        exp /= n;
                                        pot /= n;
                                }

                                if (n)
                                {                                
                                        foreach(tob in t)
                                        {
                                                   if (objectp(tob) && living(tob) && environment(tob) == environment(this_object()))
                                                {
                                                                   GIFT_D->delay_bonus(tob,
                                                                          ([ "exp"      : exp + ((tob == dob) ? exp / 10 : 0),
                                                                                 "pot"      : pot + ((tob == dob) ? pot / 10 : 0),
                                                                                 "prompt"   : "你的隊伍殺死" + name() + "之後"]));

                                                 }
                                        }
                                }
                                else
                                {
                                                                   GIFT_D->delay_bonus(dob,
                                                                          ([ "exp"      : exp,
                                                                                 "pot"      : pot,
                                                                                 "shen"      : query("shen"),
                                                                                 "mar"      : pot / 3,
                                                                                 "gongxian"      : pot / 25,
                                                                                 "gold"      : 20,
                                                                                 "prompt"   : "你在殺死" + name() + "之後"]));
                                }

        }

                message_vision(NOR + "$N" + NOR + "大叫一聲倒在地上，死了。\n" + NOR, this_object());
                destruct(this_object());

        return;
}




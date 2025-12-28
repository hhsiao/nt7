// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <ansi.h>
#include "../../cnpc.h"

inherit NPC;

int is_boss() { return 1; }

void create()
{
        object ob; 
     
        set_name(HIR + "赫連鐵樹" + NOR, ({ "helian tieshu", "helian", "tieshu" }));
        set("nickname", HIY + "一品堂大將軍" + NOR);
        set("long", 
"西夏國有個講武館，叫做一品堂，是該國國王所立，堂中招聘武功高強之士，優禮供養。\n"
        );
        
        set("age", 42);
        set("str", 55);
        set("dex", 55);
        set("con", 55);
        set("int", 55);
        set("max_qi", BOSS1_QI_BASE);
        set("eff_qi", BOSS1_QI_BASE);
        set("qi", BOSS1_QI_BASE);
        set("max_jing", to_int(BOSS1_QI_BASE * HP_JING_PERCENT));
        set("eff_jing", to_int(BOSS1_QI_BASE * HP_JING_PERCENT));
        set("jing", to_int(BOSS1_QI_BASE * HP_JING_PERCENT));
        set("max_neili", to_int(BOSS1_QI_BASE * HP_NEILI_PERCENT));
        set("neili", to_int(BOSS1_QI_BASE * HP_NEILI_PERCENT));
        set("max_jingli", to_int(BOSS1_QI_BASE * HP_NEILI_PERCENT));
        set("jingli", to_int(BOSS1_QI_BASE * HP_NEILI_PERCENT));
        
        set("level", BOSS1_LEVEL);
        set("combat_exp", 3000000000);
                set("jiali", 10000);

        if (!random(3)) set("reborn/times",3);//pfm 我必還

        set_temp("apply/parry", 500);
        set_temp("apply/dodge", 500);
        set_temp("apply/dex", 500);
        set_temp("apply/attack", 500);
        set_temp("apply/defense", 500);
        set_temp("apply/unarmed_damage", 3000);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        
  
                //set_temp("apply/add_blind", 100);//    : "致盲",                       // weapon 終極兵器 致盲-讓對手失明
                set_temp("apply/add_freeze", 15);//   : "冰凍",                       // weapon 終極兵器 冰凍-遲緩，減緩對方攻擊，攻擊pfm速度降低，無任何防禦，無躲閃，無招架，就是捱打
                set_temp("apply/add_burning", 20);//  : "灼燒",                       // weapon 終極兵器 灼燒-一定時間內目標不停的減少內力和氣血condition
                //set_temp("apply/add_dizziness", 100);//: "眩暈",                       // weapon 終極兵器 昏睡-眩暈，不能進行任何行動，但生命通常會加速回復，受到攻擊會醒來，否則15秒內一直不動，解除戰鬥狀態，昏睡本來就是一個混戰時，先把一個敵人排除出戰鬥，專心對付其他人的技能
                set_temp("apply/add_forget", 20);//   : "遺忘",                       // weapon 終極防具 遺忘-使對方忘記所有技能的絕招add_oblivion   
                set_temp("apply/add_weak", 10);//     : "虛弱",                       // weapon 終極兵器
                set_temp("apply/add_busy", 25);//     : "忙亂",                       // weapon 終極兵器

                set_temp("apply/avoid_blind", 100);//  : "忽視致盲",                   // armor/rings 終極防具
                set_temp("apply/avoid_freeze", 80);// : "忽視冰凍",                   // armor/rings 終極防具
                set_temp("apply/avoid_burning", 80);//: "忽視灼燒",                   // armor/rings 終極防具
                set_temp("apply/avoid_dizziness", 100);//: "忽視眩暈",                  // armor/rings 終極防具
                set_temp("apply/avoid_forget", 90);// : "忽視遺忘",                   // armor/rings 終極兵器
                set_temp("apply/avoid_weak", 85);//   : "忽視虛弱",                   // armor/rings 終極防具
                set_temp("apply/avoid_busy", 80);//   : "忽視忙亂",                   // armor/rings 終極防具
                set_temp("apply/reduce_busy", 80);//  : "化解忙亂",                   // armor/rings 終極防具
  
                set_temp("apply/reduce_damage", 60);//  : 化解傷害",                   // armor 終極防具 
                set_temp("apply/ap_power", 20);//  : "絕招攻擊力",         // weapon/rings
                set_temp("apply/dp_power", 35);//  : "絕招防禦力",         // armor
                set_temp("apply/da_power", 10);//  : "絕招傷害力",         // weapon/rings
                set_temp("apply/avoid_defense", 30);//  : "攻擊無視目標防禦",   // weapon/rings
                set_temp("apply/avoid_parry", 30);//  : "攻擊無視目標招架",   // weapon/rings
                set_temp("apply/avoid_dodge", 30);//  : "攻擊無視目標躲閃",   // weapon/rings
                set_temp("apply/avoid_force", 30);//  : "攻擊無視內功防禦",   // weapon/rings
                set_temp("apply/avoid_attack", 60);//  : "無視目標特殊攻擊",   // armor

        if (!random(3))
        {
                set_skill("count", to_int(BOSS1_SKILL_LV * 2));
                set_skill("martial-cognize", to_int(BOSS1_SKILL_LV * 3));
        }
        else
        {
                set_skill("count", to_int(BOSS1_SKILL_LV * 0.5));
                set_skill("martial-cognize", to_int(BOSS1_SKILL_LV * 1.2));
        }
        
                        set_skill("force", BOSS1_SKILL_LV);
                                if (random(4) == 0)
                                {
                                        set_skill("xixing-dafa", BOSS1_SKILL_LV);
                                map_skill("force", "xixing-dafa");
                                }
                                else if (random(2))
                                {
                                        set_skill("biyun-xinfa", BOSS1_SKILL_LV);        
                                map_skill("force", "biyun-xinfa");
                                }
                                else
                                {
                                        set_skill("riyue-xinfa", BOSS1_SKILL_LV);        
                                map_skill("force", "riyue-xinfa");
                                }
                        set_skill("dodge", BOSS1_SKILL_LV);
                            switch (random(5))
                        {
                                case 0:
                                        set_skill("chanchu-bufa", BOSS1_SKILL_LV);
                                        map_skill("dodge", "chanchu-bufa");
                                        break;
                                case 1:
                                        set_skill("shuishangpiao", BOSS1_SKILL_LV);
                                        map_skill("dodge", "shuishangpiao");
                                        break;
                                default:
                                        set_skill("kunlun-shenfa", BOSS1_SKILL_LV);
                                        map_skill("dodge", "kunlun-shenfa");
                                        break;
                        }

        switch (random(10))
        {
                case 0:
                        set_skill("blade", BOSS1_SKILL_LV);
                        set_skill("xuedao-daofa", BOSS1_SKILL_LV);
                        map_skill("blade", "xuedao-daofa");
                        set_skill("strike", BOSS1_SKILL_LV);
                        set_skill("yinlong-shou", BOSS1_SKILL_LV);
                        map_skill("strike", "yinlong-shou");
                        set_skill("parry", BOSS1_SKILL_LV);
                        set_skill("douzhuan-xingyi", BOSS1_SKILL_LV);
                        map_skill("parry", "douzhuan-xingyi");//斗轉
                                prepare_skill("strike", "yinlong-shou"); 
                        set("chat_chance_combat", 120);
                        set("chat_msg_combat", ({
                        (: perform_action, "blade.shi" :),
                        (: perform_action, "blade.xue" :),
                        (: perform_action, "blade.chi" :),
                        (: perform_action, "blade.ying" :),
                        (: perform_action, "blade.huan" :),
                        (: perform_action, "strike.duo" :),
                        }) );
                        break;
                default:
                        set_skill("blade", BOSS1_SKILL_LV);
                        set_skill("xuedao-daofa", BOSS1_SKILL_LV);
                        map_skill("blade", "xuedao-daofa");
                        set_skill("strike", BOSS1_SKILL_LV);
                        set_skill("yinlong-shou", BOSS1_SKILL_LV);
                        map_skill("strike", "yinlong-shou");
                        set_skill("parry", BOSS1_SKILL_LV);
                        map_skill("parry", "yinlong-shou");
                                prepare_skill("strike", "yinlong-shou"); 
                        set("chat_chance_combat", 120);
                        set("chat_msg_combat", ({
                        (: perform_action, "blade.shi" :),
                        (: perform_action, "blade.xue" :),
                        (: perform_action, "blade.chi" :),
                        (: perform_action, "blade.ying" :),
                        (: perform_action, "blade.huan" :),
                        (: perform_action, "strike.duo" :),
                        }) );
                        break;
        }
        
        
        set("gift/exp", BOSS1_GIFT_EXP);
        set("gift/pot", to_int(BOSS1_GIFT_EXP / 5));
        setup();
        
                                ob = new(__DIR__"obj/bblade");
                                ob->move(this_object()); 
                                ob->wield(); 
                                set("myweapon", ob, this_object());
        call_out("chk_blade", 1, ob);
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

void chk_blade(object blade)
{
        object me; 
        string str;

        me = this_object();
        if (!objectp(me)) return;
        
        if (!query_temp("weapon") || !objectp(query("myweapon",me)))
        {
                if (objectp(query_last_damage_from())) query_last_damage_from()->start_busy(3+random(4));//給點時間我帶武器，不論對方有多少pfm busy
                if(objectp(blade)) destruct(blade);
                blade = new(__DIR__"obj/bblade");
                set("myweapon", blade, me);
                blade->move(this_object()); 
                str = sprintf("%s" HIY "伸出手掌虛空一抓一握，%s" HIY "嗖地一聲被吸回到他手中。\n" NOR,
                                       query("name", me),
                                       query("name", blade));
                        tell_room(environment(me), str, me);
                blade->wield(); 
        }

        call_out("chk_blade", 1, blade);
        return;
}


void init()
{
        if (playerp(this_player())) kill_ob(this_player());
}

void die(object killer)
{
         int showexp;
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
        if(random(50) && //98%不能call die?
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
                                
                
                exp = to_int(exp * (random(100)+950) / 1000);
                showexp = exp;                
                                
                                CHANNEL_D->channel_broadcast(CHANL_NAME, 
                                        query("name", dob) + "於無錫杏子林擊殺"+HIY+"「一品堂大將軍」"+HIR+"赫連鐵樹"+NOR+"，獲得"+chinese_number(get_show_giftexp(dob, showexp))+"點經驗獎勵。"
                                        );
                                        
                                exp = invert_reborngiftd(dob, exp);
                                pot = exp / 5;
                                
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
                                                                   addn("xingzilin/bosshe",1,tob);addn("xingzilin/exp",exp,tob);GIFT_D->delay_bonus(tob,
                                                                          ([ "exp"      : exp + ((tob == dob) ? exp / 10 : 0),
                                                                                 "pot"      : pot + ((tob == dob) ? pot / 10 : 0),
                                                                                 "prompt"   : "你的隊伍殺死" + name() + "之後"]));

                                                 }
                                        }
                                }
                                else
                                {
                                                                   addn("xingzilin/bosshe",1,dob);addn("xingzilin/exp",exp,dob);GIFT_D->delay_bonus(dob,
                                                                          ([ "exp"      : exp,
                                                                                 "pot"      : pot,
                                                                                 "prompt"   : "你在殺死" + name() + "之後"]));
                                }

        }

                                ob = query("myweapon",me);
                                if(objectp(ob)) destruct(ob);
                destruct(this_object());

        return;
}




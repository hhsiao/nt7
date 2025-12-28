#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h"

inherit F_SSERVER;

string name() { return HIW "太極圖" NOR; }

int perform(object me, object target)
{
        mapping buff;
        object *obs;
        string msg;
        int duration;
        int damage;
        int ap, dp;
        int flag;
        int time;
        int delta;
        int i;
        int p;
        int per;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(name() + "只能空手施展。\n");

        if( (int)me->query_skill("taiji-quan", 1) < 250 )
                return notify_fail("你的太極拳不夠嫻熟，難以施展" + name() + "。\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 300 )
                return notify_fail("你的太極神功修為還不夠高，難以施展" + name() + "。\n");

        if( (int)me->query_skill("taoism", 1) < 300 )
                return notify_fail("你的道學心法修為還不夠高，難以施展" + name() + "。\n");

        if( me->query_skill_mapped("cuff") != "taiji-quan" )
                return notify_fail("你現在沒有激發太極拳，難以施展" + name() + "。\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
                return notify_fail("你現在沒有激發太極神功，難以施展" + name() + "。\n");

        if( query("jing", me)<2000 )
                return notify_fail("你現在精力不夠，難以施展" + name() + "。\n");

        if( query("neili", me)<2000 )
                return notify_fail("你現在真氣不夠，難以施展" + name() + "。\n");

             if( userp(me)&& !wizardp(me) ) 
        {
                if( (duration = BUFF_D->get_buff_overtime(me, "tjq_tu")) > 0 )
                        return notify_fail(MAG"太極圖消耗心神太甚，還需等待"+duration+"秒。\n"NOR);
        }
        
        msg = HIM "$N" HIM "淡然一笑，雙手輕輕劃了數個圈子，頓時四周的氣"
              "流波動，源源不斷的被牽引進來。\n\n" NOR;
        message_combatd(msg, me, target);

        per = me->query_skill("taiji-shengong",1)/2000 + me->query_skill("tianwei-zhengqi",1)/240;
        if(per < 1) per = 1;
        if(per > 20) per = 20;
                
        addn("neili", -1000, me);
        addn("jing", -1000, me);
        
        ap = attack_power(me, "cuff") + me->query_skill("taoism", 1);
        delta = ABILITY_D->check_ability(me, "ap_power-tjq-tu");
        if( delta ) ap += ap*delta/100;
        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = defense_power(obs[i], "force") + obs[i]->query_skill("count", 1);
                if( ap > dp * 12 / 10 ) 
                {
                        switch (random(3))
                        {
                        case 0:
                                tell_object(obs[i], HIY "恍惚之間你似乎回到了過去的世界，竟"
                                                    "然再無法控制自我，忽然眼前的一切\n"
                                                    "又全然不見，你心頭一亂，渾身一陣劇"
                                                    "痛，內力紊亂難以控制！\n" NOR);
                                break;
                        case 1:
                                tell_object(obs[i], HIW "你眼前一切漸漸的模糊起來，好像是到"
                                                    "了仙境，然而你卻覺得內息越來越亂，\n"
                                                    "四肢一陣痠痛，幾乎要站立不住。\n" NOR);

                                break;
                        default:
                                tell_object(obs[i], HIR "你耳邊忽然響起一個霹靂，眼見雷神揮"
                                                    "舞電錘向你打來，你不禁大吃一驚，\n"
                                                    "渾身上下都不聽使喚，只有高聲呼救。\n" NOR);
                                break;
                        }
                        damage = damage_power(me, "cuff");
                        damage+= me->query_all_buff("unarmed_damage");
                        damage+= damage/100*me->query_skill("tianwei-zhengqi",1);
                        damage+= damage/2000*me->query_skill("taiji-shengong",1);
                        delta = ABILITY_D->check_ability(me, "da_power-tjq-tu"); // 門派ab
                        if( delta ) damage += damage*delta/100;
        
                        if( damage < query("max_qi", obs[i])* (per + random(6)) / 100 )
                            damage = query("max_qi", obs[i])* (per + random(6)) / 100;
                        if( damage > query("max_qi", obs[i]) *2 )
                            damage = query("max_qi", obs[i])*2;                                                   
                        if( damage < 0 ) damage = query("max_qi", obs[i]) /2; 
                                                        
                            obs[i]->receive_damage("qi", damage, me);
                            obs[i]->receive_wound("qi", damage/2, me);
                                                        
                        if( damage < query("max_jing", obs[i])* (per + random(6)) / 100 )
                            damage = query("max_jing", obs[i])* (per + random(6)) / 100;                                             
                        if( damage > query("max_jing", obs[i]) *2 )
                            damage = query("max_jing", obs[i]) *2;                                                 
                        if( damage < 0 ) damage = query("max_jing", obs[i]) /2; 
 
                            obs[i]->receive_damage("jing", damage / 2, me);
                            obs[i]->receive_wound("jing", damage / 4, me);

                        p=query("qi", obs[i])*100/query("max_qi", obs[i]);

                        switch (random(3))
                        {
                        case 0:
                                msg = HIR "只見" + obs[i]->name() +
                                      HIR "手舞足蹈，忘乎所以，忽"
                                      "然大叫一聲，吐血不止！\n" NOR;
                                
                                break;
                        case 1:
                                msg = HIR "卻見" + obs[i]->name() +
                                      HIR "容貌哀慼，似乎想起了什"
                                      "麼傷心之事，身子一晃，嘔出數口鮮血！\n" NOR;
                                break;
                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "呆立當場，一動不動，有如中"
                                      "邪，七竅都迸出鮮血來。\n" NOR;
                                break;
                        }
                        if( !obs[i]->is_busy() )
                                obs[i]->start_busy(3);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        COMBAT_D->report_status(obs[i], 1);
                        addn("neili", -500, obs[i]);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIC "你發現眼前的景物似幻似真，連忙"
                                            "默運內功，不受困擾。\n" NOR);
                        addn("neili", -200, obs[i]);
                }
                if( query("neili", obs[i])<0 )
                        set("neili", 0, obs[i]);
        }


        if( !flag )
                message_combatd(HIM "然而沒有任何人受了$N"
                               HIM "的影響。\n\n" NOR, me, 0, obs);
        
        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-tjq-tu"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd 
               
        buff = // Perform Cool Dow
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "tjq_tu",
                "attr"   : "curse",
                "name"   : "太極拳·太極圖",
                "time"   : time,
                "buff_msg" : "太極圖消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
       
        ]);
        BUFF_D->buffup(buff);
        me->start_busy(1+random(2));
        return 1;
}



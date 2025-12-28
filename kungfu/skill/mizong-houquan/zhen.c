// This program is a part of NT MudLIB
// zhen.c 猴拳「震」字訣
//redl 2014

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage, flagremote = 0;
                int scale, wound, dex;
        string msg, pmsg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神功震敵只能對戰鬥中的對手使用。\n");

        if( objectp(query_temp("weapon", me)) )
                return notify_fail("你必須空手才能使用「震」字訣！\n");         
                
        if( (int)me->query_skill("mizong-houquan", 1) < 50 )
                return notify_fail("你的猴拳不夠嫻熟，不會使用「震」字訣。\n");
        if( (int)me->query_skill("cuff", 1) < 50 )
                return notify_fail("你的基本拳法不夠嫻熟，不會使用「震」字訣。\n");
                                
        if( query("neili", me)<500 )
                return notify_fail("你現在內力太弱，不能使用「震」字訣。\n");
                        
        msg = HIY "\n$N默運神功，使出迷蹤猴拳"NOR HIC"「震」"HIY "字訣，企圖以內力震傷$n。\n"NOR;

        if ( (random(me->query_skill("force") + (userp(me) ? (me->query_skill("force-cognize", 1)) : (random(me->query_skill("force-cognize", 1))) )) > target->query_skill("force") / 2 ) || 
                query("neili", me) / 3 > query("neili", target)
        )
        {       
                        if (random(me->query_skill("martial-cognize", 1)) > 500 &&
                                random(me->query_skill("force-cognize", 1)) > 500 &&
                                random(me->query_skill("force", 1)) > 1000 &&
                                random(me->query_skill("cuff", 1)) > 1000 && 
                                random(me->query_skill("mizong-houquan", 1)) > 1000
                        ) flagremote = 1;
                        
                        // calculate damage
                        damage = damage_power(me, "cuff");
                        damage += me->query_skill("force", 1) * 3;
                        damage += me->query_skill("force-cognize", 1) * 2;
                        damage += me->query_skill("martial-cognize", 1) * 2;
                        damage += damage * query("jiali", me) / 1000; 
                        
                        scale = 1;
                        dex = query("dex",target);
                        dex = dex + 2*random(dex);
                        if (sscanf(base_name(environment(me)), "/kungfu/class/misc/houwang"))
            {
                if( target->query_skill_mapped("dodge") == "lingbo-weibu")
                                scale = dex;
                                if( target->query_skill_mapped("parry") == "qiankun-danuoyi"
                                ||  target->query_skill_mapped("parry") == "douzhuan-xingyi"
                                ||  target->query_skill_mapped("parry") == "jingang-buhuaiti"
                                ||  target->query_skill_mapped("force") == "freezing-force"
                                )
                scale = dex/2;
                                if( target->query_skill_mapped("dodge") == "tiyunzong")
                                scale = dex/3;                  
                            scale = scale - random(scale);
                                if(dex<1) dex = 1;
                        }
            damage /= scale;
                        wound = 30 + random((me->query_skill("force-cognize", 1)) / 200);       
            if(userp(target) && wound > 1000)
            wound = 1000;
                        
                        addn("neili", -250, me);
                        
                        if( damage < query("qi", target) / 4 ) pmsg = HIY"結果$n受到$N的內力反震，悶哼一聲。\n"NOR;
                        else if( damage < query("qi", target) / 2 ) pmsg = HIY"結果$n被$N以內力反震，「嘿」地一聲退了兩步。\n"NOR;
                        else if( damage < query("qi", target) ) pmsg = RED"結果$n被$N以內力一震，胸口有如受到一記重錘，連退了五六步！\n"NOR;
                        else pmsg = HIR"結果$n被$N的內力一震，眼前一黑，身子向後飛出丈許！！\n"NOR;
                        
                        msg += COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : UNARMED_ATTACK), damage, wound, pmsg);
                        
                        me->start_busy(2);
                        if (! target->is_busy())
                                        target->start_busy(random(3));
                
        } else 
        {
                addn("neili", -500, me);
                me->start_busy(3);
                msg += CYN"可是$p看破了$P的企圖，並沒有上當。\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}


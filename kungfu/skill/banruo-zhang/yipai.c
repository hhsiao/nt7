//banruo-zhang's perform yipai(一拍兩散)
//mud@NT7 2015.02.15 
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
string name() { return HIW "一拍兩散" NOR; }
int perform(object me, object target)
{
        int damage,count = 0;
        int max_neili,neili;
        int ap,dp;
        string msg;
        int lunhui,budd,yjj,banruo;
                int flagremote = 0;
        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法施展" + name() + "。\n");
       
        if( !objectp(target) ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) 
           || environment(target)!=environment(me))
                return notify_fail("一拍兩散絕招只能對戰鬥中的對手使用。\n");
                
        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail("你必須空手才能使用「一拍兩散」！\n");       
        if( (int)me->query_skill("buddhism", 1) < 5000 )
                return notify_fail("你的佛法造詣太低，不能使用一拍兩散絕招對敵！\n");
                
        if( (int)me->query_skill("banruo-zhang", 1) < 1800 )
                return notify_fail("你的般若掌還不夠熟練，不能使用一拍兩散絕招對敵！\n");
                
        if( me->query_skill("yipai-liangsan", 1) < me->query_skill("banruo-zhang", 1)-100 )
                return notify_fail("你的一拍兩散還不夠熟練，不能使用一拍兩散絕招對敵！\n");
                
        if( me->query_skill("yijinjing", 1) < me->query_skill("banruo-zhang", 1)-100 )
                return notify_fail("你的易筋經功還不夠熟練，不能使用一拍兩散絕招對敵！\n");
        if( (int)me->query_skill("strike", 1) < 1800 )
                return notify_fail("你的掌法不夠嫻熟，使不出般若掌的絕招！\n");
        if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("你必須使用易筋經才能發揮一拍兩散的威力。\n");
                
        if (me->query_skill_prepared("strike") != "banruo-zhang" &&
            me->query_skill_mapped("strike") != "banruo-zhang")
                return notify_fail("你必須先將般若掌運用於掌法之中才行。\n");
//        if (me->query_skill_mapped("parry") != "banruo-zhang")
//                return notify_fail("你必須先將般若掌運用於招架之中才行。\n");
                                
        max_neili = query("max_neili",me);
        neili = query("neili",me);
        if( max_neili < 10000000 )
                return notify_fail("你內力修為不足，使不出般若掌的絕招！\n");     
        if( neili < max_neili/2 )
                return notify_fail("你現在內力不足，使不出般若掌的絕招！\n");     
             
        me->start_busy(2+random(2));
        if(!target->is_busy())
                target->start_busy(1); 
        
        ap = attack_power(me,"strike");
        ap+= attack_power(me,"force");
        ap+= me->query_skill("buddhism",1);
        
        dp = defense_power(target,"parry");
        dp+= defense_power(target,"dodge");
        
        lunhui = me->query_skill("lunhui",1);
        budd = me->query_skill("buddhism",1);
        banruo = me->query_skill("banruo-zhang",1);
        yjj = me->query_skill("yijinjing",1);
        
        budd = budd/5000;
        if(budd<1) budd = 1;
        if(budd>12) budd = 12;
        
        yjj = yjj/2000;
        if(yjj<1) yjj=1;
        if(yjj>10) yjj=10;
        
        ap = ap + ap * lunhui/1000;
        
        message_combatd(sort_msg(HIY "$N" HIY "大喝道：“吃我一掌！”。雙掌自外向裡轉了個圓圈，"
             "緩緩向$n推了過來。$N掌力未到，$n已感胸口呼吸不暢，頃刻之間，$N的掌力如怒潮般洶湧而至。\n" NOR), me, target);
        message_combatd(HIY+HBRED"【一拍兩散】！\n"NOR,me);
        if(ap/2+random(ap) > dp)
        {
            damage = damage_power(me,"strike");
            damage+= damage_power(me,"force");
            damage+= me->query_skill("force-cognize",1);
            damage+= query("jiali",me);
            damage*= budd+yjj;
            msg = HIY"$N高宣佛號";
            if(me->query_skill("yijinjing",1)> banruo-100)
            {
               damage+= damage;
               msg+= "運起"HIR"易筋經神功"NOR+HIY",將";
               count+=1;
            }
            if(me->query_skill("luohan-quan",1)> banruo-100)
            {
               damage+= damage;
               msg+= HIR"羅漢拳，";
               count+=1;
            }
            if(me->query_skill("nianhua-zhi",1)> banruo-100)
            {
               damage+= damage;
               msg+= HIR"拈花指，";
               count+=1;
            }
            if(me->query_skill("qianye-shou",1)> banruo-100)
            {
               damage+= damage;
               msg+= HIR"如來千葉手，";
               count+=1;
            }
            if(me->query_skill("sanhua-zhang",1)> banruo-100)
            {
               damage+= damage;
               msg+= HIR"散花掌，";
               count+=1;
            }
            if(me->query_skill("yizhi-chan",1)> banruo-100)
            {
               damage+= damage;
               msg+= HIR"一指禪，";
               count+=1;               
            }
            if(me->query_skill("yipai-liangsan",1)> banruo-100)
            {
               damage+= damage;
               msg+= HIR"一拍兩散"HIY"等少林絕技一一融合，功力大增！\n";
               count+=1;               
            }
            if(target->is_bad())
            {
               damage = damage + damage/2;
               msg+= HIC"$N想起$n生平所作所為皆為奸惡之舉，掌力又加了五成！\n";
            }
            if(budd == 12) count+=1;
            if(count == 8 && random(3)) 
            {
               if(random(budd)> 4 && damage < query("max_qi",target))
               damage = query("max_qi",target);
               else if (damage < query("max_qi",target)/2)
               damage = query("max_qi",target)/2;
               addn("neili",-max_neili/2,me);
               msg+= NOR+RED"$N"NOR+RED"孤注一擲，將全身功力匯於一掌之內拍出，成敗在此一舉！\n";
            }
            message_combatd(sort_msg(msg), me, target); 
            if(random(budd) > 3 || budd == 12)
                        {
                            if(random(100) < 85)
                                flagremote = 1;
                                else if(banruo > 12000)
                                flagremote = 1;
                        }
                        if(query("sex/times",me))
                        damage = damage / 2 ;
            if(query("combat_exp",me) /3*2 + random( query("combat_exp",me)) > query("combat_exp",target))
            msg = COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : UNARMED_ATTACK), damage, 100 + lunhui/5, 
                  HIY"$n猝不及防，被這排山倒海般的掌力重重擊中，頓時魂飛魄散！\n"NOR);       
            else
            msg = COMBAT_D->do_damage(me, target, (flagremote ? REMOTE_ATTACK : UNARMED_ATTACK), damage/2, 100 + lunhui/5,
                  HIY"兩股掌力相交，嗤嗤有聲，$N和$n均退了三步。$n一霎間只感全身乏力，真氣提不上來!\n"NOR);
            
            addn("neili", -max_neili/budd,me);
        }
        else
        {
            msg = CYN "$n" CYN "倒吸一口涼氣，飛身一跳，狼狽地躲過這招。\n" NOR;
            addn("neili", -max_neili/40,me);
        }
        if(query("neili",me) < 0) me->set("neili",0);
        message_combatd(msg, me, target);
        if(wizardp(me) && query("id",me)=="mud") tell_object(me,"count:damage="+count+":"+damage+"\n");
        return 1;
}


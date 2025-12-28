// hua.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp;
        int my_max, tg_max;
        int suck;
        object weapon;

        if (target == me) target = offensive_target(me);

        if( query("no_fight", environment(me)) )
                return notify_fail("在這裡不能攻擊他人。\n");

        if (! objectp(target))
                return notify_fail("你要化誰的內力？\n");

        if( query("race", target) != "人類" )
                return notify_fail("搞錯了！只有人才能有內力！\n");

        if (me->is_busy())
                return notify_fail("你現在正忙，無法化他人內力。\n");

        my_max=query("max_neili", me);
        tg_max=query("max_neili", target);

        if ((int)me->query_skill("huagong-dafa", 1) < 100)
                return notify_fail("你的化功大法功力不夠，不能施展！\n");

        if( query("neili", me)<200 )
                return notify_fail("你的內力不夠，不能施展化功大法。\n");

        if( query("max_neili", me)-me->query_all_buff("max_neili") >= 
            (me->query_neili_limit()-me->query_all_buff("max_neili"))*3 )
                return notify_fail("你的內力修為似乎已經達到了瓶頸，再吸取也是徒勞。\n"); 

        if( query("neili", target)<10 || 
            query("max_neili", target)<10 || query("no_suck", target) )
                return notify_fail(target->name() +
                                   "已然內力渙散，不必再化了。\n");

        if( query("max_neili", target)>query("max_neili", me)*10 )
                return notify_fail( target->name() +
                        "的內功修為遠勝於你，你無法從化他的內力！\n");
                        
        if( !objectp(weapon=query_temp("weapon", me)) )
                message_combatd(HIR "$N" HIR "全身骨節爆響，雙臂暴長數尺，手掌"
                        "刷的一抖，粘向$n！\n" NOR,
                        me, target);
        else
                message_combatd(HIR "$N" HIR "把手中的" + weapon->name() +
                                HIR "一揚，全身骨節爆響，雙臂暴長數尺逼向$n" HIR + "，$p"
                                HIR "連忙架住。\n" NOR,
                                me, target);
                                
        if( target->query_skill("taixuan-gong", 1) )
        {
                message_sort(HIG "\n$N" HIG "剛將手掌接觸到$n" HIG "肌膚，猛然覺得一股無比強大的"
                             "內勁反壓回來，化功大法的內力卻猶如石沉大海。$N" HIG "大吃一驚，連"
                             "忙將手縮回，再也不敢接近。\n" NOR);
                return 1;

        }

        //me->want_kill(target);
        
        if (living(target))
                if (! target->is_killing(me)) target->kill_ob(me);

        sp = attack_power(me, "force")+me->query_skill("bingchan-gong", 1);
        dp = defense_power(target, "dodge");

        if ((sp / 2 + random(sp) > random(dp)) || ! living(target))
        {
                suck = 1 + me->query_skill("huagong-dafa", 1) / 3;

		if( me->query_skill("bingchan-gong", 1) )
                   suck += suck* (me->query_skill("bingchan-gong",1)/100*4) /100; 
		
		if( me->query_family() == "星宿派" )
                        suck *= 2;
                        
                tell_object(target, HIR "你只覺天頂骨裂，全身功力"
                            "貫腦而出，如融雪般消失得無影無蹤！\n" NOR);
                            
                addn("max_neili", -suck, target);
                addn("max_neili", suck, me);
                if( query("max_neili", target)<1 )
                        set("max_neili", 0, target);

                me->start_busy(2);
                target->start_busy(random(2));
        } else
        {       
                message_combatd(HIY "可是$p" HIY "看破了$P"
                                HIY "的企圖，內力猛地一震，借勢溜"
                                "了開去。\n" NOR, me, target);
                me->start_busy(3);
        }

        return 1;
}


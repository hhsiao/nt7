// maxsuck.c

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        int sp, dp;
        int my_max, tg_max;
        int sucked;
        object weapon;

        if (! target || target == me) target = offensive_target(me);

        if( query("no_fight", environment(me)) )
                return notify_fail("在這裡不能攻擊他人。\n");

        if (! objectp(target) || ! me->is_fighting(target))
                return notify_fail("你要吸取誰的丹元？\n");

        if( query("race", target) != "人類" || 
            query("not_living", target) )
                return notify_fail("搞錯了！只有活著的生物才能有丹元！\n");

        my_max=query("max_neili", me);
        tg_max=query("max_neili", target);
        if ((int)me->query_skill("beiming-shengong", 1) < 90)
                return notify_fail("你的北冥神功功力不夠，不能吸取對方的丹元！n");

        if( query("neili", me) < 20 )
                return notify_fail("你的內力不夠，不能使用北冥神功。\n");

        if( ((int)me->query_neili_limit()-me->query_all_buff("max_neili"))*3 <= 
            my_max-me->query_all_buff("max_neili"))
                return notify_fail("你的內功水平有限，再吸取也是徒勞。\n");

        if( query("max_neili", target)<100 || query("no_suck", target) )
                return notify_fail( target->name() +
                        "丹元渙散，功力未聚，你無法從他體內吸取任何東西！\n");

        if( query("max_neili", target)<query("max_neili", me)/20 )
                return notify_fail( target->name() +
                        "的內功修為遠不如你，你無法從他體內吸取丹元！\n");

        if( !objectp(weapon=query_temp("weapon", me)) )
                message_combatd(HIG "$N" HIG "全身一振，伸出右手，輕輕握在$n"
                        HIG "的手臂上。\n\n" NOR, me, target);
        else
                message_combatd(HIR "$N" HIR "把手中的" + weapon->name() +
                                HIR "一揚，伸出右手逼向$n" HIR + "，$p"
                                HIR "連忙架住。\n" NOR,
                                me, target);
        
        if( target->query_skill_mapped("force") == "taixuan-gong" )
        {
                tell_object(target, HIW + me->name() + HIW "伸出右手，輕輕握在你的手"
                             "臂上，試圖吸取你的內力，但是你體內的太玄真氣猛地將"
                             "其反彈回去。\n");

                return notify_fail(HIG "你伸出右手，輕輕握在" + target->name() +
                                   HIG "的手臂上，卻猛的感覺一股內勁將你的手彈回。\n" NOR);
        }                

        if( living(target) && !target->is_killing(me) )
        {
                me->want_kill(target);
                target->kill_ob(me);
        }

        sp = me->query_skill("force");
        dp = target->query_skill("force");

        if( (sp + random(sp) > dp + random(dp) ) || ! living(target) )
        {
                tell_object(target, HIR "你只覺全身乏力，全身功力如"
                            "融雪般消失得無影無蹤！\n" NOR);
                tell_object(me, HIG "你覺得" + target->name() +
                            HIG "的丹元自手掌源源不絕地流了進來。\n" NOR);

                sucked = 1 + me->query_skill("beiming-shengong", 1) / 3;
                
                if( me->query_skill("xiaoyao-you",1 ) > 100 )
                        sucked += sucked* (me->query_skill("xiaoyao-you",1)/100*4) /100; 
                        
                if( me->query_family() == "逍遙派" )
                        sucked *= 2;
                        
                addn("max_neili", -sucked, target);
                addn("max_neili", sucked, me);
                if( query("max_neili", target)<1 )
                        set("max_neili", 0, target);

                me->start_busy(2);
                target->start_busy(2);
                addn("neili", -10, me);
        }
        else
        {       
                message_combatd(HIY "可是$p" HIY "看破了$P" HIY
                                "的企圖，機靈地溜了開去。\n" NOR,
                                me, target);
                me->start_busy(3);
        }

        return 1;
}


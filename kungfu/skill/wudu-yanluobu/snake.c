// snake.c  金蛇遊身

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int ap, dp, time;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「金蛇遊身」只能對戰鬥中的對手使用。\n");

        if( (int)me->query_skill("wudu-yanluobu", 1) < 50 )
                return notify_fail("你的五毒煙蘿步火候不夠，不能使出「金蛇遊身」。\n");

        if( query("neili", me)<500 )
                return notify_fail("你現在內力太弱，不能使用「金蛇遊身」。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正手忙腳亂，你還亂轉什麼，趕快進攻吧！\n");
                        
        msg = HIC "$N身行忽的一變，使出「金蛇遊身」的絕技，身法越來越快。\n\n\n只見$N飛快的繞場遊走，瞻之在前，望之在後，一時間到處都是$N的身影。\n"NOR;
        message_combatd(msg, me, target);

        addn("neili", -500, me);
        ap = attack_power(me, "dodge");
        dp = defense_power(target, "dodge");
        
        //redl
        if( ap / 5 * 4 + random(ap) > dp )
        {
                time = ap / 200 + 3;
                if (time>16) time = 16;
                target->start_busy(time);
                msg = HIR"$n不由得一陣手足無措，被$N連攻數招！\n"NOR;
        }
        else
        {
                time = 200;
                if (userp(me)) time -= 150;
                if (!random(time)) {
                        msg = HIR"可是$n以靜制動，緊守門戶，絲毫不受$N的影響,$N太豁出去，直接跳暈了！\n"NOR;
                        me->unconcious(target);
                } else {
                        msg = HIR"可是$n以靜制動，緊守門戶，絲毫不受$N的影響,$N自己倒累的滿頭大汗！\n"NOR;
                        me->start_busy(4);
                }
        }
        message_combatd(msg, me, target);
        return 1;
}

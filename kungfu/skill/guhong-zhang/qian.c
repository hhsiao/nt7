#include <ansi.h>
#include <combat.h>

#define QIAN "「" HIG "千山孤鴻影" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;
        int skill;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(QIAN "只能對戰鬥中的對手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(QIAN "只能空手施展。\n");

        if ((int)me->query_skill("guhong-zhang", 1) < 80)
                return notify_fail("你孤鴻掌法不夠嫻熟，難以施展" QIAN "。\n");

        if (me->query_skill_mapped("strike") != "guhong-zhang")
                return notify_fail("你沒有激發孤鴻掌法，難以施展" QIAN "。\n");

        if (me->query_skill_prepared("strike") != "guhong-zhang")
                return notify_fail("你沒有準備孤鴻掌法，難以施展" QIAN "。\n");

        if (me->query_skill("force") < 100)
                return notify_fail("你的內功修為不夠，難以施展" QIAN "。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在的真氣不夠，難以施展" QIAN "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");
        
        skill = me->query_skill("guhong-zhang", 1);
        
        ap = attack_power(me, "strike");
        dp = defense_power(target, "parry");

        msg = HIC "\n$N" HIC "雙掌陡然連續拍出，剛中帶柔，一招"
              "「" HIG "千山孤鴻影" HIC "」，雙掌帶風，已將$n" 
              HIC "籠罩在掌風之中。\n" NOR;
        message_sort(msg, me, target);

        if (random(ap) > dp / 2)
        {
                msg = HIR "結果$n" HIR "目不暇接，頓時被$N" HIR "掌"
                      "風所困，頓時陣腳大亂。\n" NOR;
                addn_temp("apply/attack", skill/2, me);
        } else
        {
                msg = HIY "$n" HIY "看清$N" HIY "這幾招的來路，但"
                      "內勁所至，剛柔並濟，也只得小心抵擋。\n" NOR;          
        }
        message_vision(msg, me, target);

        attack_time += 3 + random(ap / 40);

        if (attack_time > 6)
                attack_time = 6;

        addn("neili", -attack_time*20, me);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->start_busy(1 + random(attack_time));
        addn_temp("apply/attack", -skill/2, me);

        return 1;
}
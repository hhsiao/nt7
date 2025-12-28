// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIM "赤心連環決" NOR; }

int perform(object me, object target)
{
        string msg;
        int ap, dp;
        int attack_time, i;
        int v, level;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(name() + "只能空手施展。\n");

        if ((level = me->query_skill("chilian-shenzhang", 1)) < 100)
                return notify_fail("你赤練神掌不夠嫻熟，難以施展" + name() + "。\n");

        if (me->query_skill_prepared("strike") != "chilian-shenzhang")
                return notify_fail("你沒有準備赤練神掌，難以施展" + name() + "。\n");

        if (me->query_skill("force") < 100)
                return notify_fail("你的內功修為不夠，難以施展" + name() + "。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        ap = attack_power(me, "strike");
        dp = defense_power(target, "parry");

        msg = HIC "$N" HIC "暗運內功，但見$N" HIC "雙掌微微呈顯"
              "赤色，陡然連續反轉，\n使出一招「" HIM "赤心連環決" HIC
              "」，掌風凌厲，將$n" HIC "籠罩在雙掌之中。\n" NOR;

        message_combatd(msg, me, target);

        ap *= 2;
        if (ap / 2 + random(ap) > dp)
        {
                msg = HIR "$n" HIR "心中一驚，卻被$N" HIR "掌"
                      "風所困，頓時陣腳大亂。\n" NOR;
                v = level;
        } else
        {
                v = 0;
                msg = HIY "$n" HIY "看清$N" HIY "這幾招的來路，但"
                      "內勁所至，掌風犀利，也只得小心抵擋。\n" NOR;
        }
        message_combatd(msg, me, target);

        attack_time += 4 + random(ap / 100);

        if (attack_time > 6)
                attack_time = 6;

        addn("neili", -attack_time*20, me);

        addn_temp("apply/attack", v, me);
        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, 0, 0);
        }
        addn_temp("apply/attack", -v, me);
        me->start_busy(2 + random(4));

        return 1;
}

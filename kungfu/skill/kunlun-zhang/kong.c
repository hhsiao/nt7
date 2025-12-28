#include <ansi.h>
#include <combat.h>

#define KONG "「" HIR "日入空山" NOR "」"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(KONG "只能對戰鬥中的對手使用。\n");

        if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                return notify_fail(KONG "只能空手施展。\n");

        skill = me->query_skill("kunlun-zhang", 1);

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顧不暇，放膽攻擊吧。\n");

        if (skill < 120)
                return notify_fail("你崑崙掌法等級不夠，難以施展" KONG "。\n");
 
        if (me->query_skill_mapped("strike") != "kunlun-zhang")
                return notify_fail("你沒有激發崑崙掌法，難以施展" KONG "。\n");

        if (me->query_skill_prepared("strike") != "kunlun-zhang")
                return notify_fail("你沒有準備崑崙掌法，難以施展" KONG "。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在的真氣不夠，難以施展" KONG "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIW "$N" HIW "陡然施出崑崙掌法絕技「" NOR + HIR "日入空山"
              NOR + HIW "」，一掌猛然拍出，掌影重重疊疊，籠罩$n" HIW "四"
              "面八方。\n" NOR;

        ap = attack_power(me, "strike");
        dp = defense_power(target, "parry");
        if (ap / 2 + random(ap) > dp)
        {
                addn("neili", -150, me);
                damage = damage_power(me, "strike");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "$n" HIR "只見$P" HIR "的無數掌影"
                                           "向自己壓來，一時不知該如何抵擋，頓時"
                                           "連中數招，無暇反擊。\n" NOR);
                me->start_busy(1);
                target->start_busy(ap / 90 + 2);
        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN
                       "的企圖，巧妙的拆招，沒露半點破綻"
                       "。\n" NOR;
                addn("neili", -80, me);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

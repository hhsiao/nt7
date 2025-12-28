//redl 2014
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "雲海明燈" NOR; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int skill;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能在戰鬥中對對手使用。\n");

        if( query_temp("weapon", me) ||
            query_temp("secondary_weapon", me) )
                return notify_fail("你必須空手才能施展" + name() + "。\n");

        if (me->query_skill("force") < 200)
                return notify_fail("你的內功的修為不夠，無法施展" + name() + "。\n");

        if (skill = me->query_skill("piaoxue-zhang", 1) < 150)
                return notify_fail("你的飄雪穿雲掌修為不夠，無法施展" + name() + "。\n");

        if( query("neili", me)<200 || query("max_neili", me)<2000 )
                return notify_fail("你的真氣不夠，無法施展" + name() + "。\n");

        if (me->query_skill_mapped("strike") != "piaoxue-zhang")
                return notify_fail("你沒有激發飄雪穿雲掌，無法施展" + name() + "。\n");

        if (me->query_skill_prepared("strike") != "piaoxue-zhang")
                return notify_fail("你沒有準備使用飄雪穿雲掌，無法施展" + name() + "。\n");

        if (! living(target))
               return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIW "$N" HIW "一聲暴喝，陡然施出飄雪穿雲掌絕技「雲海明燈」，瞬"
              "間連續攻出數招。\n" NOR;
        message_combatd(msg, me);

        addn("neili", -100, me);
        skill = skill + me->query_skill("jingxin", 1)*10;

                addn_temp("apply/unarmed_damage", skill/5, me);
        // 第一招
        addn_temp("apply/attack", skill/2, me);
        COMBAT_D->do_attack(me, target, weapon, TYPE_LINK);

        // 第二招
        addn_temp("apply/attack", skill/2, me);
        COMBAT_D->do_attack(me, target, weapon, TYPE_LINK);

        // 第三招
        addn_temp("apply/attack", skill, me);
        COMBAT_D->do_attack(me, target, weapon, TYPE_LINK);
        if( BUFF_D->check_buff(me, "ljz_fengyun") ) 
                COMBAT_D->do_attack(me, target, weapon, TYPE_LINK);

        // 消除攻擊修正
        addn_temp("apply/attack", -skill*2, me);
                addn_temp("apply/unarmed_damage", -skill/5, me);

        me->start_busy(1 + random(3));

        return 1;
}

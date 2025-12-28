// This is player's own perform (Write by Lonely@nt2)
// Create by 降頭師(Wudu) at Wed Jun 24 13:28:27 2015
// 君臨天下(dan)
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int is_player_perform() { return 1; }

string name() { return HIW "君臨天下" NOR; }

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int attack;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if (member_array("hand", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if( !objectp(weapon=query_temp("weapon", me) )
                    || query("skill_type", weapon) != "hand" )
                        return notify_fail("你所使用的武器不對，難以施展" + name() + "。\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                        return notify_fail(name() + "只能空手使用。\n");
        }

        if ((int)me->query_skill("mmqf-hand", 1) < 400)
                return notify_fail("你" + to_chinese("mmqf-hand") + "不夠嫻熟，難以施展" + name() + "。\n");

        if (member_array("hand", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("hand") != "mmqf-hand")
                        return notify_fail("你沒有準備" + to_chinese("mmqf-hand") + "，難以施展" + name() + "。\n");
        }

        if( query("neili", me)<300 )
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIW "$N端坐微笑，忽而臉現莊嚴之色，$n立刻匍匐在地，虔誠膜拜。" + "\n" + NOR;

        ap = attack_power(me, "hand");
        dp = defense_power(target, "parry");

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = damage_power(me, "hand")*9;
                msg += COMBAT_D->do_damage(me, target, attack, damage, 490, HIM "$N端坐微笑，忽而臉現莊嚴之色，$n立刻匍匐在地，虔誠膜拜。" + "\n" NOR);
                addn("neili", -200, me);
                me->start_busy(1);
                /*
                if (! target->is_busy())
                        target->start_busy(2);
                */
        } else
        {
                msg += NOR + CYN "$N端坐微笑，忽而臉現莊嚴之色，$n立刻匍匐在地，虔誠膜拜。" + "\n" NOR;
                addn("neili", -100, me);
                me->start_busy(2);
        }

        message_sort(msg, me, target);
        return 1;
}

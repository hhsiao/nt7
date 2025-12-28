// This is player's own perform (Write by Lonely@nt2)
// Create by 劍人(Dlf) at Tue Mar  3 12:07:49 2015
// 龍之式(long)
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIW "龍之式" NOR; }

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

        if (member_array("unarmed", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if( !objectp(weapon=query_temp("weapon", me) )
                    || query("skill_type", weapon) != "unarmed" )
                        return notify_fail("你所使用的武器不對，難以施展" + name() + "。\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                        return notify_fail(name() + "只能空手使用。\n");
        }

        if ((int)me->query_skill("longfeng-unarmed", 1) < 400)
                return notify_fail("你" + to_chinese("longfeng-unarmed") + "不夠嫻熟，難以施展" + name() + "。\n");

        if (member_array("unarmed", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("unarmed") != "longfeng-unarmed")
                        return notify_fail("你沒有準備" + to_chinese("longfeng-unarmed") + "，難以施展" + name() + "。\n");
        }

        if( query("neili", me)<300 )
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIW "$N雙手合結「龍之式」，腳踏陰陽八卦陣,方圓十里美女如雲，陣陣美妙的音樂，令$n心神不定，神情恍惚。突然間一圈圈碧芒圍向$n，震得$n吐血連連！" + "\n" + NOR;

        ap = attack_power(me, "unarmed");
        dp = defense_power(target, "parry");

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = damage_power(me, "unarmed");
                msg += COMBAT_D->do_damage(me, target, attack, damage, 90, HIM "$n尚未回過心神，結果發現$N的「龍之式」強大沖入體內，登感呼吸不暢。乘此良機，$N的強大力道如同排山倒海一般奔向$n，周遭狂風大作，飛砂走石！" + "\n" NOR);
                addn("neili", -200, me);
                me->start_busy(1);
                /*
                if (! target->is_busy())
                        target->start_busy(2);
                */
        } else
        {
                msg += NOR + CYN "$n拼力縱身後躍，險險避過此致命一擊，心有餘悸。" + "\n" NOR;
                addn("neili", -100, me);
                me->start_busy(2);
        }

        message_sort(msg, me, target);
        return 1;
}

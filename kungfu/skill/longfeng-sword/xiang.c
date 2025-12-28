// This is player's own perform (Write by Lonely@nt2)
// Create by 文人(Dlf) at Sun May 17 23:49:04 2015
// 龍鳳呈祥(xiang)
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int is_player_perform() { return 1; }

string name() { return HIW "龍鳳呈祥" NOR; }

string *weapon_sk = ({
        "sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int count, damage;
        int attack_time;
        int attack, i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能對戰鬥中的對手使用。\n");

        if (member_array("sword", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if( !objectp(weapon=query_temp("weapon", me) )
                    || query("skill_type", weapon) != "sword" )
                        return notify_fail("你所使用的武器不對，難以施展" + name() + "。\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                        return notify_fail(name() + "只能空手使用。\n");
        }

        if ((int)me->query_skill("longfeng-sword", 1) < 400)
                return notify_fail("你" + to_chinese("longfeng-sword") + "不夠嫻熟，難以施展" + name() + "。\n");

        if (member_array("sword", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("sword") != "longfeng-sword")
                        return notify_fail("你沒有準備" + to_chinese("longfeng-sword") + "，難以施展" + name() + "。\n");
        }

        if( query("neili", me)<500 )
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIW "$N$HIW$身影慢慢的浮現在$n$HIW$面前，只見$N$HIW$灑出無數晶瑩剔透的$圍繞在$n$HIW$周圍。刀光劍影的世界霎時間沉寂在這柔和的雪光之中，好一記溫柔纏綿的$$HIM$縱情山水間，揮灑天地情!" + "\n" + NOR;

        ap = attack_power(me, "sword");
        dp = defense_power(target, "parry");

        if (ap / 2 + random(ap) > dp)
        {
                damage = damage_power(me, "sword")*7;
                msg += COMBAT_D->do_damage(me, target, attack, damage, 380, HIM "$n$HIW$頓時沉寂在這夢一般的景象之中，如痴如醉中被雪玲瓏擊中了!$n$HIW$完全陷入龍鳳呈祥的威力之中無法自拔。$n看著劍光從前心穿過" + "\n" NOR);
                addn("neili", -200, me);

                /*
                if (! target->is_busy())
                        target->start_busy(2);
                */
        } else
        {
                msg += NOR + CYN "可$n$HIY$並沒有被這絢麗的雪景所吸引,依然屹立在雪花飛舞的幻景中！" + "\n" NOR;
                addn("neili", -100, me);
        }

        message_sort(msg, me, target);

        msg = HIW "$N" HIW "餘勢未盡，招式陡然變得凌厲無比，一轉念間已然攻出數招。\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
                count = ap / 20;
                msg += HIR "$n" HIR "見$P" HIR "來勢迅猛之極，一時不知該如"
                       "何作出抵擋，竟呆立當場。\n" NOR;
        } else
        {
                msg += HIY "$n" HIY "見$p" HIY "來勢迅猛之極，甚難防備，連"
                       "忙振作精神，小心抵擋。\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        attack_time = 3;
        attack_time+=query("reborn/times", me)*2;
        if (attack_time > 8)
                attack_time = 8;

        addn("neili", -attack_time*20, me);

        addn_temp("apply/attack", count, me);
        addn_temp("apply/damage", count, me);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;

                COMBAT_D->do_attack(me, target, (member_array("sword", weapon_sk) == -1 ? 0 : weapon), TYPE_LINK);
        }
        addn_temp("apply/attack", -count, me);
        addn_temp("apply/damage", -count, me);
        me->start_busy(3 + random(attack_time/ 3));
        return 1;
}

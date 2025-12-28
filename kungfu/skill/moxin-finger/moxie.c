// This is player's own perform (Write by Lonely@nt2)
// Create by 枯枝(Kuzhi) at Wed May 27 02:38:43 2015
// 魔邪翻天(moxie)
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int is_player_perform() { return 1; }

string name() { return HIW "魔邪翻天" NOR; }

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

        if (member_array("finger", weapon_sk) != -1)
        {
                attack = WEAPON_ATTACK;
                if( !objectp(weapon=query_temp("weapon", me) )
                    || query("skill_type", weapon) != "finger" )
                        return notify_fail("你所使用的武器不對，難以施展" + name() + "。\n");
        } else
        {
                attack = UNARMED_ATTACK;
                if( query_temp("weapon", me) || query_temp("secondary_weapon", me) )
                        return notify_fail(name() + "只能空手使用。\n");
        }

        if ((int)me->query_skill("moxin-finger", 1) < 400)
                return notify_fail("你" + to_chinese("moxin-finger") + "不夠嫻熟，難以施展" + name() + "。\n");

        if (member_array("finger", weapon_sk) == -1)
        {
                if (me->query_skill_prepared("finger") != "moxin-finger")
                        return notify_fail("你沒有準備" + to_chinese("moxin-finger") + "，難以施展" + name() + "。\n");
        }

        if( query("neili", me)<300 )
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("對方都已經這樣了，用不著這麼費力吧？\n");

        msg = HIW "$N指勁飛出，鋪天蓋地，完全撥反了防禦百丈內一切事物的運行方向。向前變成向後，向左變成向右，向上變成向下，向外變成向內，天地萬物運轉，全部反其道而行之，$n整個人都感覺不好了！" + "\n" + NOR;

        ap = attack_power(me, "finger");
        dp = defense_power(target, "parry");

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = damage_power(me, "finger")*9;
                msg += COMBAT_D->do_damage(me, target, attack, damage, 490, HIM "結果$n閃避不及，$N的指勁頓時透體而入，整個人原地亂轉，口中鮮血狂噴，連退百步。" + "\n" NOR);
                addn("neili", -200, me);
                me->start_busy(1);
                /*
                if (! target->is_busy())
                        target->start_busy(2);
                */
        } else
        {
                msg += NOR + CYN "$p見勢不妙，運氣凝神一動都不敢動，硬是抗過$P的這記殺招，看著身旁逆轉的一切，深深的吸了一口冷氣！" + "\n" NOR;
                addn("neili", -100, me);
                me->start_busy(2);
        }

        message_sort(msg, me, target);
        return 1;
}

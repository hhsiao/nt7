// This program is a part of NITAN MudLIB
// qingxin.c 「清心劍」

#include <ansi.h>

inherit F_SSERVER;
string name() { return "清心劍"; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int skill;
        mapping buff, data;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「清心劍」只能對戰鬥中的對手使用。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "sword" )
                return notify_fail("你使用的武器不對。\n");

        if (skill = (int)me->query_skill("damo-jian", 1) < 200)
                return notify_fail("你的達摩劍法不夠嫻熟，不會使用「清心劍」。\n");

        if( query("neili", me)<300 )
                return notify_fail("你現在真氣不夠，無法使用「清心劍」。\n");

        if (me->query_skill_mapped("sword") != "damo-jian")
                return notify_fail("你沒有激發達摩劍法，無法使用「清心劍」。\n");

        if( BUFF_D->check_buff(target, "dmj_qingxin") )
                return notify_fail("對方剛剛才中過達摩清心劍，你不必再用一次了。\n");

        msg = HIM "$N" HIM "將" + weapon->name() + "輕輕一抖，一股"
              "劍氣悄然而出，分作數路攻向$n" HIM "！\n" NOR;

        addn("neili", -200, me);

        ap = attack_power(me, "sword");
        dp = defense_power(target, "force");

        if (ap / 2 + random(ap) > dp)
        {
                msg += HIR "結果$p" HIR "覺得渾身一麻，手足軟"
                       "軟的竟然使不出一點力道！\n" NOR;
                
                data = ([
                        "attack" : -skill/3,
                        "defense": -skill/3,
                ]);
                
                buff = ([
                        "caster":me,
			"target": target,
			"type":"dmj_qingxin",
			"attr":"curse",
			"name":"達摩劍·清心劍",
			"time": skill/5,
                        "buff_data": data,
			"buff_msg": msg,
			"disa_msg": HIR "你覺得力氣恢復了一些。\n" NOR,
                ]);                
        } else
        {
                msg += CYN "可是$p" CYN "內力深厚，使得$P" CYN
                       "這一招沒有起到任何作用。\n" NOR;
                message_combatd(msg, me, target);
                me->start_busy(3);
        }
        
        return 1;
}

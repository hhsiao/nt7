// This program is a part of NITAN MudLIB
// duo.c  金蛇劍法  (奪魄)

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, ap, dp;
        string msg;
        mapping buff, data;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("奪魄只能對同地方的對手使用。\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("奪魄只能對戰鬥中的對手使用。\n");

        if( (int)me->query_skill("jinshe-jian", 1) < 100 )
                return notify_fail("你的金蛇劍法不夠嫻熟，不會使用「奪魄」。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在內力太弱，不能使出奪魄。\n");

        if( BUFF_D->check_buff(target, "jinshe_duo") )
                return notify_fail(query("name", target)+"正在魂飛魄散間，快放手攻擊啊!\n");

        msg = HIW "$N突然眼中金芒大盛，一股寒意破空直襲$n。\n"NOR;
        addn("neili", -400, me);

        ap = attack_power(me, "sword");
        dp = defense_power(target, "dodge");

        if (ap / 2 + random(ap) > dp)
        {
                msg += WHT"$p被嚇得魂飛魄散，只見對方攻勢大盛，越戰越勇。\n"NOR;
                if( !target->is_busy() ) target->start_busy(3);
                addn("neili", -100, me);
                skill = me->query_skill("jinshe-jian",1);

                data = ([
                        "attack"  : -skill/2,
                        "defense" : -skill/2,
                ]);
                buff = ([
                        "caster":me,
			"target": target,
			"type":"jinshe_duo",
			"attr":"curse",
			"name":"金蛇劍法．奪魂",
			"time": skill/3,
                        "buff_data": data,
			"buff_msg": msg,
			"disa_msg": RED"$N終於從奪魄的陰影裡恢復了出來。\n"NOR,
			"disa_type": 1,
                ]);
        }
        else
        {
                msg += HIY"$p沉著應戰，沒有受到“奪魄”攻擊的影響！\n"NOR;
        }
        message_combatd(msg, me, target);
        me->start_busy(1);
        return 1;
}

// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

string name() { return HIY "圓滿勢" NOR; }

inherit F_SSERVER;

int perform(object me)
{
        mapping buff, data;
        string msg;
        object weapon;
        string wp;
        int skill;

        if( BUFF_D->check_buff(me, "ryl_yuan") )
                return notify_fail("你現在正在施展" + name() + "。\n");

        if( !objectp(weapon=query_temp("weapon", me) )
            || query("skill_type", weapon) != "hammer" )
                return notify_fail("你所使用的武器不對，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("hammer") != "riyue-lun")
                return notify_fail("你沒有激發日月輪法，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("force") != "longxiang-gong")
                return notify_fail("你沒有激發龍象般若功，難以施展" + name() + "。\n");

        if ((int)me->query_skill("riyue-lun", 1) < 120)
                return notify_fail("你的日月輪法火候不足，難以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("你的內功火候不足，難以施展" + name() + "。\n");

        if( query("max_neili", me)<1500 )
                return notify_fail("你的內力修為不足，難以施展" + name() + "。\n");

        if( query("neili", me)<300 )
                return notify_fail("你現在的真氣不足，難以施展" + name() + "。\n");

        wp = weapon->name();

        msg = HIY "$N" HIY "吐氣揚聲，施出日月輪法「" HIW "圓滿勢"
                        HIY "」，手中" + wp + HIY "運轉如飛，迅速護住周身要"
                        "害。\n" NOR;

        skill = me->query_skill("riyue-lun", 1);

        addn("neili", -200, me);
        data = ([
                "defense": skill/2,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "ryl_yuan",
                "attr"  : "bless",
                "name"  : "日月輪法·圓滿勢",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的圓滿勢運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting())
                me->start_busy(2);

        return 1;
}

#include <ansi.h>
#include <combat.h>

string name() { return HIR "燃木真焰" NOR; }

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        int skill;
        string msg;

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "blade" )
                return notify_fail(name() + "你必須用刀法施展。\n");

        if( BUFF_D->check_buff(me, "rmdf_zhenyan") )
                return notify_fail(name() + "正在施展中。\n");

        if ((int)me->query_skill("ranmu-daofa", 1) < 180)
                return notify_fail("你的燃木刀法修為不夠，難以施展" + name() + "。\n");

        if( query("max_neili", me)<2500 )
                return notify_fail("你的內力修為不足，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("你沒有激發燃木刀法為刀法，難以施展" + name() + "。\n");

        if( query("neili", me)<500 )
                return notify_fail("你現在的真氣不足，難以施展" + name() + "。\n");


        msg = HIY "$N" HIY "雙手持刀，對天咆哮，所施正是燃木刀法絕學「"
              HIR "燃木真焰" HIY "」。\n霎時呼嘯聲大作，但見一股澎湃無比的罡勁"

              "至$N" HIY "刀間湧出，雲貫向$N" HIY "而去。\n" NOR;

        skill = me->query_skill("ranmu-daofa",1);

        data = ([
                "attack" : skill*2/5,
                "defense": skill*2/5,
                "damage" : skill*2,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "rmdf_zhenyan",
                "attr"  : "bless",
                "name"  : "然木刀法．燃木真焰",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的燃木真焰運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);

        addn("neili", -400, me);
        if (me->is_fighting())
                me->start_busy(2);
        return 1;
}

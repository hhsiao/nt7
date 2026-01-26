// powerup.c 先天功加力

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用先天功來提升自己的戰鬥力。\n");

        if( query("neili", me)<150 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);

        msg = HIY "$N微一凝神，運起先天氣功，足底塵土泛起，全身真"
                        "氣衝關欲出。\n" NOR;

        data = ([
                "attack" : skill/2,
                "defense": skill/2,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "先天功．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的先天功運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);

        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

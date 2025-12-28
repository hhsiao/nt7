// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用易筋鍛骨內功提升自己的戰鬥力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的真氣不夠！");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIW "$N暗自凝神，提運九陰真氣，全身漸漸升起一層白霧。\n" NOR;

        data = ([
                "attack": skill/2,
                "defense":skill/2,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "易筋鍛骨·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的易筋鍛骨運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

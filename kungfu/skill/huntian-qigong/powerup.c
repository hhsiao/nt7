// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping buff, data;

        if (target != me)
                return notify_fail("你只能用混天氣功來提升自己的戰鬥力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運用類似的武功了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIR "$N微一凝神，運起混天氣功，全身骨節發出一陣爆豆般的聲響ⅵ\n" NOR;

        data =  ([
                        "attack" : skill/3,
                        "defense": skill/3,
                ]);
        buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "powerup",
                        "attr"  : "bless",
                        "name"  : "混天氣功．戰神",
                        "time"  : skill,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的混天氣功運行完畢，將內力收回丹田。\n",

                ]);
        BUFF_D->buffup(buff);

        if( me->is_fighting() )
                me->start_busy(3);

        return 1;
}

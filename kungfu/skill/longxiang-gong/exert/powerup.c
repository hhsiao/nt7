// powerup.c 龍相功加力

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if( target != me )
                return notify_fail("你只能提升自己的戰鬥力。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的真氣不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運用類似的武功了。\n");

        skill = me->query_skill("force");

        msg = HIR "$N" HIR "大喝一聲，全身骨骼節節暴響，一股"
                       "迅猛的罡氣向四周擴散開來！\n" NOR;

        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "龍象般若功．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的龍象般若功運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

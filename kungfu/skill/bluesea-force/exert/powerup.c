// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        mapping buff, data;
        string msg;

        if (target != me)
                return notify_fail("你只能用南海玄功提升自己的戰鬥力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠!");

        if( BUFF_D->check_buff(me,"powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIC "$N" HIC "大喝一聲，一股氣浪登時如波"
                        "濤一般散佈開來，直吹得四周飛沙走石！\n" NOR;

        data = ([
                "attack" : skill*2/5,
                "defense": skill*2/5,
        ]);
        buff = ([
	        "caster": me,
	        "target": me,
	        "type"  : "powerup",
	        "attr"  : "bless",
	        "name"  : "南海玄功·戰神",
	        "time"  : skill,
	        "buff_data": data,	
	        "buff_msg" : msg,
	        "disa_msg" : "你的南海玄功運行完畢，將內力收回丹田。\n",
        ]);

        BUFF_D->buffup(buff);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

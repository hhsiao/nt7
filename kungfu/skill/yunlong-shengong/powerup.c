// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if( target != me ) return notify_fail("你只能用雲龍神功提升自己的戰鬥力。\n");

        if( query("neili", me)<100)return notify_fail("你的內力不夠。\n");
        if( BUFF_D->check_buff(me, "powerup") )return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("force", -100, me);
        me->receive_damage("qi", 0);

        msg = HIR "$N長吸一口氣，運起雲龍神功已將全身潛力盡數提起！\n" NOR;

        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "雲龍神功·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的雲龍神功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

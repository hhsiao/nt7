#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用聖火神功來提升自己的戰鬥力。\n");

        if ((int)query("neili", me) < 150)
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") ) 
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -150, me);
        msg = HIM "$N默運聖火神功，臉色先由黃翻紫，緊接著由紫翻藍，再由藍翻紅，最後又恢"
                        "復為黃色，甚為詭異。\n" NOR;
        
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "聖火神功·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的聖火神功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

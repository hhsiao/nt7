// shield.c 先天無極勁

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if ((int)me->query_skill("xiantian-gong", 1) < 50)
                return notify_fail("你的先天功還不夠深厚。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在的真氣不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        msg = HIW "$N" HIW "深深吸了一口氣，雙臂一振，一股渾厚的氣勁登"
              "時盤旋在身邊四周。\n" NOR;     

        data = ([
                "armor" : skill/2,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "先天功·護體神功",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的先天功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn("neili", -100, me);
        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

// This program is a part of NITAN MudLIB
// shield.c 護體神功

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if( target != me ) 
                return notify_fail("你只能用小無相功來運護體神功。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");
                
        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功\中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = MAG "$N長吸一口氣，運起護體神功，身上衣衫緩緩漲起。ⅵ\n" NOR;

        data = ([
                "armor" : skill/2,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "小無相功·護體神功",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的小無相功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

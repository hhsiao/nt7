// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
 
        if( target != me ) 
                return notify_fail("你只能用戰神心經來提升自己的戰鬥力。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的內力不夠。\n");
        if( BUFF_D->check_buff(me, "powerup") ) 
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);

        msg = HIR "$N凝神息氣，運起戰神心經，只見一股輕煙繚繞周身。\n" NOR;

        data = ([
                "attack" : skill*2/3,
                "defense": skill*2/3,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "戰神心經·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的戰神心經運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

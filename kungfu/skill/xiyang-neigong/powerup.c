// powerup.c 西洋內功

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用西洋內功來提升自己的戰鬥力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") ) 
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -90, me);
        me->receive_damage("qi", 0);

        msg = HIG "$N" HIG "口中“荷荷”大叫，渾身的肌肉如同"
                        "充了氣一般忽然膨脹起來，威勢攝人！\n" NOR;

        data = ([
                "attack" : skill/4,
                "defense": skill/4,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "西洋內功·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的西洋內功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

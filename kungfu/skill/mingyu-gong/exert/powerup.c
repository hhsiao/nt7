// powerup.c 明玉功加力

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用明玉功來提升自己的戰鬥力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") ) 
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIR "$N" HIR "運起明玉功，全身皮膚瞬間變得晶瑩無比，光滑異常，整個人\n"
                        "神聖而不可侵犯，散發著令人心顫的寒氣。\n" NOR;

        data = ([
                "attack" : skill*2/5,
                "defense": skill*2/5,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "明玉功·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的明玉功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        
        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

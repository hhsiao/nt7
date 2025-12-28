// This program is a part of NT MudLIB
// Written by Lonely@nitan.org

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping buff, data;
 
        if( target != me ) 
                return notify_fail("你只能用八荒六合功來提升自己的戰鬥力。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運用類似的武功了。\n");
                
        if( query("neili", me) < 200 )
                return notify_fail("你的內力不夠。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);

        msg = HIR "$N" HIR "凝神息氣，運起八荒六合唯我獨尊功，只見一股輕煙悄然繚繞周身。\n" NOR;
        
        data =  ([
                        "attack" : skill/2,
                        "defense": skill/3,
                ]);
        buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "powerup",
                        "attr"  : "bless",
                        "name"  : "八荒六合功·戰神",
                        "time"  : skill,
                        "buff_data": data,      
                        "buff_msg" : msg,
                        "disa_msg" : "你的八荒六合唯我獨尊功運行完畢，將內力收回丹田。\n",
                        
                ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;       
}

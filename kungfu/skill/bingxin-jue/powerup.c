// powerup.c 

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        mapping buff, data;
        string msg;
        
        if (target != me)
                return notify_fail("你只能用冰心決來提升自己的戰鬥力。\n");
                
        if( query("neili", me)<300 )
                return notify_fail("你的內力不夠。\n");
                
        if( BUFF_D->check_buff(me,"powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -200, me);
        me->receive_damage("qi", 0);
        
        msg = HIW "$N" HIW "默運冰心決，全身關節一陣爆響，一股至陰的內勁從渾身經脈迸發出來。\n" NOR;
        
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);
               
        buff = ([
	        "caster": me,
	        "target": me,
	        "type"  : "powerup",
	        "attr"  : "bless",
	        "name"  : "冰心決·戰神",
	        "time"  : skill,
	        "buff_data": data,	
	        "buff_msg" : msg,
	        "disa_msg" : "你的冰心決運行完畢，將內力收回丹田。\n",
        ]);

        BUFF_D->buffup(buff);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

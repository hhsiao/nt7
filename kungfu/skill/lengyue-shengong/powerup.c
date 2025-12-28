// freeze.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用冷月神功提升自己的戰鬥力。\n");

        if( query("neili", me)<300 )
                return notify_fail("你的真氣不夠！");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIW "$N" HIW "全身關節“格啦格啦”一陣爆響，一股至陰的內勁從渾身經脈迸發出來。\n" NOR;
        
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
                "damage" : skill*5,
                "unarmed_damage":skill*5,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "冷月神功·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的冷月神功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;       
}



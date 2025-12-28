// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        int di;
        object weapon;

        if( target != me )
                return notify_fail("你只能用臨濟莊提升自己的戰鬥力。\n");

        if( (int)query("neili", me) < 100 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") ) 
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        if( query("sex", me) ) di = 0; else di = skill * 2;
        if( di > 10000 ) di = 10000;

        msg = MAG "$N" MAG "微一凝神，運起臨濟莊，一聲嬌喝，"
                        "四周的空氣彷彿都凝固了！\n" NOR;

        if( objectp(weapon = query_temp("weapon", me)) )
        {
                if (di >= 95)
                        message_combatd(HIR "$N" HIR "臉色一沉，運起臨濟莊神通，霎時間" +
                                        weapon->name() + HIR "光華四射，漫起無邊殺意。\n" NOR, me);
                else
                if (di >= 80)
                        message_combatd(HIR "$N" HIR "潛運內力，只見" +
                                        weapon->name() + HIR "閃過一道光華，氣勢攝人，令人肅穆。\n" NOR, me);
                else
                if (di >= 30)
                        message_combatd(HIR "$N" HIR "默運內力，就見那" +
                                        weapon->name() + HIR "隱隱透出一股光芒，閃爍不定。\n" NOR, me);
        }
        
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
                "damage" : di,
                "unarmed_damage": di,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "臨濟十二莊·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的臨濟十二莊運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

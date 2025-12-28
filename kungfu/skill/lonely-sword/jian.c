#include <ansi.h>

string name() { return MAG "劍心通明" NOR; }

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        string msg;
        int skill;

        if( !query("yuanshen", me) )
                return notify_fail("你還沒有悟道，還不能施展"+name()+"。\n");

        if (me->query_skill_mapped("sword") != "lonely-sword")
                return notify_fail("你還沒有激發獨孤九劍。\n");

        if( !query("lonely-sword/nothing", me) )
                return notify_fail("你還沒有進入無招境界，何談劍心通明？\n");

        if ((int)me->query_skill("lonely-sword", 1) < 1000)
                return notify_fail("你的獨孤九劍等級不夠，難以施展" + name() + "。\n");

        if( BUFF_D->check_buff(me, "dgjj_jian") ) 
                return notify_fail("你已經運起" + name() + "了。\n");

        if( !objectp(weapon=query_temp("weapon", me)) )
                return notify_fail("你所使用的武器不對！\n");

        if( query("skill_type", weapon) != "sword" )
                return notify_fail("你所使用的武器不對！\n");

        if( query("neili", me)<250 )
                return notify_fail("你此時的內力不足，難以施展" + name() + "。\n");

        msg = MAG "$N" MAG "凝神聚氣，揮灑手中兵器，進入無招無我，劍心通明境界！\n\n" NOR;

        if (me->is_fighting())
                me->start_busy(1);

        skill = me->query_skill("lonely-sword", 1);

        data = ([
                "damage": skill*3,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dgjj_jian",
                "attr"  : "bless",
                "name"  : "獨孤九劍·劍心通明",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的劍心通明運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn("neili", -200, me);
        return 1;
}
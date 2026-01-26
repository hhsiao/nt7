#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用吸星大法來提升自己的戰鬥力。\n");

        if( query("neili", me)<150 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);
        msg = HIG "$N" HIG "深深呼入一口氣，緩緩吐出，頓時全身真"
                        "氣蒸騰，被罡勁所籠罩。\n" NOR;

        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "吸星大法．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的吸星大法運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

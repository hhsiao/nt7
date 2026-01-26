#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用太玄功來提升自己的防禦力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的真氣不夠。\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 40)
                return notify_fail("你的太玄功等級不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIG "$N" HIG "默默運功，昔日俠客島石壁上的口訣一一"
                        "呈現，太玄功內勁已護於全身。\n" NOR;

        data = ([
                "armor": skill,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "太玄功．護體神功",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的太玄功運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

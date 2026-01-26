// shield.c 護體神功

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用怒海狂濤來提升自己的防禦力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if ((int)me->query_skill("surge-force",1) < 50)
                return notify_fail("你的怒海狂濤修為不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIC "$N" HIC "雙臂輕輕一展，一股勁氣登時籠罩全身！\n" NOR;

        data = ([
               "armor": skill/2,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "怒海狂濤．護體神功",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的怒海狂濤運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
                mapping buff, data;
                string msg;

        if (target != me)
                return notify_fail("你只能用戰神心經來提升自己的防禦力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if ((int)me->query_skill("zhanshen-xinjing", 1) < 50)
                return notify_fail("你的戰神心經修為不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIW "$N" HIW "默默凝神聚氣，運起戰神心經，頓時一股"
                        "白霧至身後騰起，籠罩全身。\n" NOR;

        data = ([
                "armor": skill/2,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "戰神心經．護體神功",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的戰神心經運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);

        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

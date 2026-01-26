// shield.c 紫徽心法之護體神功
//

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用紫徽心法來提升自己的防禦力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if ((int)me->query_skill("zihui-xinfa",1) < 50)
                return notify_fail("你的紫徽心法修為不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIW "$N" HIW "手指扣成北斗七星圖形，運起紫徽心法，"
                        "頓時全身紫蘊朦朧，衣袖飄揚！\n" NOR;

        data = ([
                "armor" : skill/2,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "紫徽心法．護體神功",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的紫徽心法運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

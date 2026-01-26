// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用段氏心法來提升自己的戰鬥力。\n");

        if( query("neili", me)<150 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -50, me);
        me->receive_damage("qi", 0);

        msg = HIY "$N" HIY "暗自凝神，運起段氏心法，"
                        "臉上顯出一股祥和之意，頗具王者風範。\n" NOR;

        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "段氏心法．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的段氏心法運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

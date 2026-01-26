// This program is a part of NITAN MudLIB
// powerup.c

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping buff, data;

        if (target != me)
                return notify_fail("你只能用北冥神功提升自己的戰鬥力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運用類似的武功了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        //message_combatd(HIG "$N" HIG "將內力運遍渾身諸大要穴，"
        //                "然後收氣丹田，雙目一睜，登時精光四射！\n" NOR, me);
        msg = MAG "$N" MAG "長長吸了口氣，神凝丹田，息遊紫府，身若凌虛而超華嶽，氣如沖霄而撼北辰。\n" NOR;

        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "北冥神功．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的北冥神功運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

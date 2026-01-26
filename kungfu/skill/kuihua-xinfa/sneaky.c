// kuihua-xinfa (protect)

#include <ansi.h>

int exert(object me, object target)
{
        mapping buff;
        string msg;
        int skill;
        int time;

        if( target != me )
                return notify_fail("葵花心法只能對自己使用。\n");

        if( query("neili", me)<1000 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "shade_vision") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("kuihua-xinfa",1);
        if (skill<90)
                return notify_fail("你的葵花心法還不夠嫻熟。\n");

        msg = HIW "$N微一凝神，運起葵花心法，整個人如同被煙霧籠罩一般，漂忽不定。\n"
                        "鬼魅至極。\n" NOR;

        addn("neili", -300, me);

        time = skill/200;
        time += ABILITY_D->check_ability(me, "add-khxf-sneaky"); // ab門派

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shade_vision",
                "attr"  : "bless",
                "name"  : "葵花心法．隱身",
                "time"  : time,
                "buff_data": "shade_vision",
                "buff_msg" : msg,
                "disa_msg" : BOLD "$N的葵花心法運行完畢，全身忽的一頓，現出整個身形。\n" NOR,
                "disa_type": 1,

        ]);
        BUFF_D->buffup(buff);

        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

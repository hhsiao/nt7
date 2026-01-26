// This program is a part of NT MudLIB
// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        mapping buff, data;
        string msg;

        if( target != me )
                return notify_fail("你只能用不死神龍大法提升自己的戰鬥力。\n");

        if( (int)me->query_skill("busi-shenlong",1) < 50 )
                return notify_fail("你的內功火候還不夠，無法使用不死神龍大法！\n");

        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠!\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運用類似的武功了。\n");

        skill = me->query_skill("force");

        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIR "$N雙目赤紅，縱聲大呼：洪教主神通護佑，眾弟子勇氣百倍，以一當百，以百當萬！\n"NOR;
        //tell_object(me,HIW"你頓時感覺武功大進，勁力比先前大了數倍！\n" NOR);

        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "不死神龍．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的不死神龍大法運行完畢，汗如泉湧，呼呼喘氣。\n",

        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

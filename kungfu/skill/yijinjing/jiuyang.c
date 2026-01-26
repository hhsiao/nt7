// This program is a part of NT MudLIB
// jiuyang.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping buff, data;

        if( !query("can_exert/yijinjing/jiuyang", me) )
                return notify_fail("你還沒有領悟過少林九陽真氣呢！\n");

        if ((int)me->query_skill("yijinjing", 1) < 140)
                return notify_fail("你的易筋經修為如此之淺還想運用九陽真氣？\n");

        if( query("max_neili", me)<1500 )
                return notify_fail("你的內力修為太差，多多打坐吧。\n");

        if( query("neili", me)<300 )
                return notify_fail("你的真氣不夠。\n");

        if( /*BUFF_D->check_buff(me, "powerup")
                || BUFF_D->check_buff(me,"dodgeup")
                || */BUFF_D->check_buff(me,"atkup") )
                return notify_fail("你已經在運用類似的武功了。\n");


        msg = HIR"\n$N潛運少林九陽神功，體內真氣澎湃不息，全身佛光流動，寶相莊嚴！\n" NOR;

        skill = me->query_skill("yijinjing",1);
        addn("neili", -300, me);
        me->receive_damage("qi", 0);

        data =
        ([
                "attack" : skill/2,
        ]);
        buff =
        ([
                "caster": me,
                "target": me,
                "type"  : "atkup",
                "attr"  : "bless",
                "name"  : "易筋經．九陽真氣",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你將九陽真氣收回丹田，面露慈祥笑容。\n",
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

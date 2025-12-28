#include <ansi.h>

#define HUA "「" MAG "化蝶" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;  
        string msg;
        int count, cnt, skill;

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你已經運起" HUA "了。\n");

        if ((int)me->query_skill("zhuangzi-wu", 1) < 150)
                return notify_fail("你的莊子舞等級不夠，難以施展" HUA "。\n");

        if ((int)me->query_dex() < 32)
                return notify_fail("你的身法不夠，難以施展" HUA "。\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("你的內功火候不夠，難以施展" HUA "。\n");

        if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("你的輕功修為不夠，難以施展" HUA "。\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的內力修為不夠，難以施展" HUA "。\n");

        if( query("neili", me)<250 )
                return notify_fail("你此時的內力不足，難以施展" HUA "。\n");

        msg = MAG "$N" MAG "一聲清嘯，身形一展，舞步宛如行雲流水、彩碟飛"
              "揚，速度變得異常敏捷。\n\n" NOR;
        
        
        skill = me->query_skill("zhuangzi-wu", 1);
        cnt = (int)((int)me->query_condition("drunk") / 50);

        count = skill / 50 + cnt;

        if (me->is_fighting())
                me->start_busy(2);

        data = ([
                "dex": count,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "attr"  : "bless",
                "name"  : "莊子舞·化蝶",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的化蝶運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn("neili", -200, me);
        return 1;
}

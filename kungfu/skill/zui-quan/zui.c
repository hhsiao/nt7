// zui.c 羅漢醉酒

#include <ansi.h>

#define PFM_NAME        "羅漢醉酒"

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int count;
        int skill;
 
        if( query("neili", me)<150 )
                return notify_fail("你的真氣不足以施展「" + PFM_NAME + "」。\n");

        if( BUFF_D->check_buff(me, "zuiquan_zui") )
                return notify_fail("你已經竭力提升你的身法了。\n");
        
        if ((int)me->query_skill("zui-quan", 1) < 80)
                return notify_fail("你的醉拳還不到家，無法施展「" + PFM_NAME + "」。\n");

        msg = HIY "$N" HIY "忽地身形一變，雙拳虛握，使出一招「" + PFM_NAME +
              HIY "」，猶如金盃在手。\n"
              HIG "看似步履踉蹌，醉態可拘，但身形卻靈活之極！\n" NOR;

        addn("neili", -100, me);

        skill = me->query_skill("zui-quan", 1);
        count = skill / 50 + (int)me->query_condition("drunk") / 50;
        
        data = ([
                "dex": count, 
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "醉拳·羅漢醉酒",
                "time"  : skill/3,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的羅漢醉酒運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        me->start_busy(1 + random(3));
        return 1;
}

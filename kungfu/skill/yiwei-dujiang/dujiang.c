#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;  
        string msg;
        int count, cnt, skill;

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你已經運起「一葦渡江」了。\n");

        if ((int)me->query_skill("yiwei-dujiang", 1)< 150)
                return notify_fail("你的一葦渡江等級不夠，難以施展此項絕技！\n");

        if ((int)me->query_dex() < 30)
                return notify_fail("你的身法不夠使用「一葦渡江」絕技！\n");

        if ((int)me->query_skill("force", 1)< 150)
                return notify_fail("你的內功火候不夠，難以施展此項絕技！\n");

        if ((int)me->query_skill("dodge", 1)< 150)
                return notify_fail("你的輕功修為不夠，不會使用此項絕技！\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的內力修為不夠使用「一葦渡江」！\n");

        if( query("neili", me)<250 )
                return notify_fail("你此時的內力不足！\n");

        msg = HIB "$N" HIB "運起心意氣混元功，施展「一葦渡江」絕技,"
                  "身形一展，整個人頓時凌空飄起，身體變得越來越輕。\n" NOR;
        
        message_combatd(msg, me, target);
        skill = me->query_skill("yiwei-dujiang", 1);
        cnt =(int)( (int)me->query_condition("drunk") / 3);

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
                "name"  : "一葦渡江·一葦渡江",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的一葦渡江運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn("neili", -200, me);
        return 1;
}

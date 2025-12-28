#include <ansi.h>

string name() { return HIY "一葦渡江" NOR; }

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        string msg;
        int count, skill;

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你已經運起" + name() + "了。\n");

        if ((int)me->query_skill("shaolin-shenfa", 1) < 150)
                return notify_fail("你的少林身法等級不夠，難以施展" + name() + "。\n");

        if ((int)me->query_dex() < 33)
                return notify_fail("你的身法不夠，難以施展" + name() + "。\n");

        if ((int)me->query_skill("force", 1) < 150)
                return notify_fail("你的內功火候不夠，難以施展" + name() + "。\n");

        if ((int)me->query_skill("dodge", 1) < 150)
                return notify_fail("你的輕功修為不夠，難以施展" + name() + "。\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的內力修為不夠，難以施展" + name() + "。\n");

        if( query("neili", me)<250 )
                return notify_fail("你此時的內力不足，難以施展" + name() + "。\n");

        msg = HIY "$N" HIY "足尖輕點地面，施展一葦渡江，凌空躍起，身形頓時變得輕鬆自如。\n\n" NOR;

        skill = me->query_skill("shaolin-shenfa", 1);

        count = skill / 50;

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
                "name"  : "少林身法·一葦渡江",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的一葦渡江運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        addn("neili", -200, me);
        return 1;
}

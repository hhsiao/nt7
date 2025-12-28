#include <ansi.h>

inherit F_SSERVER;

string name() { return HIY "飛天神行" NOR; }

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int count, skill;

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你已經運起" + name() + "了。\n");

        if ((int)me->query_skill("sixiang-bufa", 1) < 150)
                return notify_fail("你的四象步法等級不夠，難以施展" + name() + "。\n");

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

        msg = HIY "$N" HIY "足尖輕點地面，凌空躍起，身形頓時變得飄忽不定，難以捉摸。\n\n" NOR;
        
        skill = me->query_skill("sixiang-bufa", 1);

        count = skill / 40;

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
                "name"  : "四象步法·飛天神行",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的飛天神行運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn("neili", -200, me);
        return 1;
}

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int count, skill;

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你已經運起「九陰歸元」了。\n");

        if ((int)me->query_skill("shexing-lifan", 1)< 150)
                return notify_fail("你的蛇行狸翻等級不夠，難以施展此項絕技！\n");

        if ((int)me->query_dex() < 30)
                return notify_fail("你的身法不夠使用「九陰歸元」絕技！\n");

        if ((int)me->query_skill("force", 1)< 150)
                return notify_fail("你的內功火候不夠，難以施展此項絕技！\n");

        if ((int)me->query_skill("dodge", 1)< 150)
                return notify_fail("你的輕功修為不夠，不會使用此項絕技！\n");

        if( query("max_neili", me)<1000 )
                return notify_fail("你的內力修為不夠使用「九陰歸元」！\n");

        if( query("neili", me)<250 )
                return notify_fail("你此時的內力不足！\n");

        msg = HIW "$N" HIW "運起九陰真氣，雙臂骨骼一陣爆響，身形一展，整"
                  "個人頓時凌空飄起，速度變得異常敏捷。\n" NOR;
        

        skill = me->query_skill("shexing-lifan", 1);

        count = skill / 50;

        if (me->is_fighting())
                me->start_busy(2);
        
        data = ([
                "str": count,
                "dex": count,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "attr"  : "bless",
                "name"  : "蛇行狸翻·九陰歸元",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的九陰歸元運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        addn("neili", -200, me);
        return 1;
}

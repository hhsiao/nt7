#include <ansi.h>

inherit F_CLEAN_UP;

#define FIREICE "「" HIW "冰" HIR "火" HIW "九重天" NOR "」"

int exert(object me, object target)
{
        mapping buff, data;
        int skill;
        string fam;
        string msg;
        
        fam = query("family/family_name", me);

        if( userp(me) && !query("skybook/item/xuanbingjiu", me) )
                 return notify_fail("你所學的內功中沒有這種功能。\n");

        if (target != me)
                return notify_fail("你只能用" FIREICE "來提升自己的戰鬥力。\n");

        if( BUFF_D->check_buff(me, "fireice") )
                return notify_fail("你現在正在施展" FIREICE "。\n");

        if ((int)me->query_skill("luohan-fumogong", 1) < 180)
                return notify_fail("你羅漢伏魔功火候不足，難以施展" FIREICE "。\n");

        if( query("max_neili", me)<4000 )
                return notify_fail("你的內力修為不足，難以施展" FIREICE "。\n");

        if( query("neili", me)<500 )
                return notify_fail("你現在的內力不足，難以施展" FIREICE "。\n");

        skill = me->query_skill("luohan-fumogong", 1);
        addn("neili", -300, me);
        me->receive_damage("qi", 0);

        msg = HIC "$N" HIC "縱聲長嘯，運轉「" HIW "冰"
                        HIR "火" HIW "九重天" HIC "」真氣，聚力"
                        "於掌間，光華流動，煞為壯觀。\n" NOR;

        data = ([
                "unarmed_damage": skill*4, 
                "damage": skill*4,
                "armor": skill*4,
      ]); 

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "fireice",
                "attr"  : "bless",
                "name"  : "羅漢伏魔功·冰火九重天",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的冰火九重天運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        
        if (me->is_fighting())
                me->start_busy(3);

        return 1;
}

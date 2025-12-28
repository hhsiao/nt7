#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        string fam;
        
        fam = query("family/family_name", me);

        // 要求只有喝過玄冰碧火酒或是少林派玩家才能施展
        if (userp(me)
           && fam != "少林派"
            && !query("skybook/item/xuanbingjiu", me) )
                return notify_fail("你所學的內功中沒有這種功能。\n");

        if (target != me)
                return notify_fail("你只能用羅漢伏魔神功來提升自己的戰鬥力。\n");

        if( query("neili", me)<150 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        if( query("skybook/item/xuanbingjiu", me )
           && fam == "少林派")
                msg = HIY "$N" HIY "高呼一聲佛號，運起羅漢伏魔神"
                                "功，全身皮膚一半呈現" NOR + HIB "靛青" HIY
                                "色，另一半卻為" HIR "血紅" HIY "色。\n"
                                NOR;
        else

        if (fam == "少林派")
                msg = HIY "$N" HIY "高呼一聲佛號，運起羅漢伏魔神"
                                "功，全身真氣澎湃，衣衫隨之鼓脹。\n"
                                NOR;

        else
                msg = HIY "$N" HIY "微一凝神，運起羅漢伏魔神功，"
                                "全身肌膚竟交替呈現出" NOR + HIB "靛青" HIY
                                "與" HIR "血紅" HIY "兩色。\n" NOR;

 
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "羅漢伏魔神功·戰神",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的羅漢伏魔神功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting())
                me->start_busy(3);
        return 1;
}

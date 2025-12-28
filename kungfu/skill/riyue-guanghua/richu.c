// richu.c 日月光華 之 日出東方

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        int delta;

        if( query("gender", me) != "無性" && !query("yuanshen", me))
                return notify_fail("你的性別與日月內功相斥，無法使用此絕招！\n");  

        if (target != me)
                return notify_fail("你只能用日月光華來提升自己的潛力。\n");

        if ((int)me->query_skill("riyue-guanghua",1) < 100)
                return notify_fail("你的日月光華修為太低，無法施展「日出東方」。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") ) 
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -120, me);
        me->receive_damage("qi", 0);
        
        msg = HIR "$N" HIR "一聲怪嘯，雙目變得赤紅，雙足一點，身子騰空而起，"
                    "四周頓時熱浪翻湧，灸熱難當。\n" NOR;

        delta = ABILITY_D->check_ability(me, "power-rygh-richu"); // 門派ab
        if( delta ) skill += skill*delta/100;
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
                "damage" : skill*3,
                "dex"    : skill/20,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "日月光華·日出東方",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的日出東方運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        if (me->is_fighting()) me->start_busy(3);

        return 1;
}

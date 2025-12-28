// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int i;
        mapping data, buff;
        
        if (! me->is_fighting())
                return notify_fail("你只能在戰鬥種使用諸天化身步。\n");

        if ((int)me->query_skill("linji-zhuang", 1) < 100)
                return notify_fail("你的臨濟十二莊還不夠火候，使不出諸天化身步。\n");  

        if ((int)me->query_skill("anying-fuxiang", 1) < 100)
                return notify_fail("你的暗影浮香還不夠火候，使不出諸天化身步。\n");  

        if( query("jing", me)<500 )
                return notify_fail("你現在精不夠。\n");

        if( query("neili", me)<500 )
                return notify_fail("你現在內力不夠。\n");

        if( BUFF_D->check_buff(me,"dodgeup") )
                return notify_fail("你已經在運用類似的武功了。\n");

        msg = HBYEL "$N使出暗影浮香的諸天化身步，身手登時更加靈巧！\n\n" NOR; 

        addn("neili", -200+random(100), me);
        me->recieve_damage("jing", 50);
        
        i = me->query_skill("linji-zhuang", 1) / 5;
        data = ([
                "dex" : i,
                "con" : i,      
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "attr"  : "bless",
                "name"  : "暗影浮香·諸天化身步",
                "time"  : me->query_skill("force") / 3,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你停止了諸天化身步，深深的吸了口氣。\n",                        
        ]);
        BUFF_D->buffup(buff);
        return 1;
}

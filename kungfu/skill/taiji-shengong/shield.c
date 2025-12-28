// This program is a part of NT MudLIB

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        
        if( target != me )
                return notify_fail("你只能用太極神功來提升自己的防禦力。\n");

        if( query("neili", me)<100 )
                return notify_fail("你的真氣不夠。\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 40 )
                return notify_fail("你的太極神功等級不夠。\n");

        if( BUFF_D->check_buff(me, "shield") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIR "$N" HIR "默唸太極神功的口訣：他"
                            "強由他強，清風拂山岡。他橫任他橫，"
                            "明月照大江……\n剎那間只見$N" 
                        HIR "全身頓時浮現出一層剛猛的勁氣，將$P"
                        HIR "全全籠罩。\n" NOR;

        data = ([
                "armor": skill/2,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "shield",
                "attr"  : "bless",
                "name"  : "太極神功·護體神功",
                "time"  : skill,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的太極神功運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(2);

        return 1;
}

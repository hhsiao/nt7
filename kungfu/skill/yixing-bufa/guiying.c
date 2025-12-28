// guiying.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string name() { return "無形鬼影"; }

int perform(object me, object target)
{
        mapping buff;
        object weapon;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「無形鬼影」只能在戰鬥中使用。\n");

        if ((int)me->query_skill("yixing-bufa", 1) < 100 )
                return notify_fail("你的意形步法等級不夠，不能使出「無形鬼影」！\n");

        if ((int)me->query_skill("dodge", 1) < 100 )
                return notify_fail("你的基本輕功極不夠嫻熟，不能使出「無形鬼影」！\n");

        if ( me->query_skill_mapped("dodge") != "yixing-bufa"
             || me->query_skill_mapped("force") != "busi-shenlong")
                return notify_fail("你現在無法使出「無形鬼影」進行牽制！\n");

        if( query("neili", me)<300 )
                return notify_fail("你現在真氣太弱，不能使出「無形鬼影」！\n");

        if( query("neili", me)<1000 )
                return notify_fail("你現在內力太弱，不能使出「無形鬼影」！\n");

        if( target->is_busy() )
                return notify_fail("對手已經手忙腳亂了,快點攻擊吧！\n");

        if( BUFF_D->check_buff(me, "yxbf_guiying") )
                return notify_fail("你已經使出「無形鬼影」步法！\n");

        msg = HIB"$N前後遊走，身形閃動，腳踏意形步法，化出數個身形。\n"
                "$n被此「無形鬼影」所迷惑，手足無措，不知哪個$N是真，哪個是假。\n"NOR;
        target->start_busy(4);
        me->start_busy(1);
        addn("neili", -200, me);
        skill = me->query_skill("yixing-bufa", 1)/3;

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "yxbf_guiying",
                "attr"  : "bless",
                "name"  : "碧波神功·戰神",
                "time"  : skill,
                "buff_data": "guiying",      
                "buff_msg" : msg,
                "disa_msg" : HIB"$N長吁一聲，放慢步法，分身立即消失不見！\n"NOR,
                "disa_type": 1,
                        
        ]);
        BUFF_D->buffup(buff);

        return 1;
}

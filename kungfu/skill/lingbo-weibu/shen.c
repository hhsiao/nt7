// This program is a part of NITAN MudLIB

#include <ansi.h>

string name() { return MAG "神光離合" NOR; }

int perform(object me, object target)
{
        string msg;
        mapping buff;
        int time;

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法施展" + name() + "。\n" NOR);

        if( me->query_skill("lingbo-weibu", 1) < 1000 )
                return notify_fail("你的凌波微步還不夠熟練，難以施展" + name() + "。\n" NOR);

        if( query("jingli", me)<2000 )
                return notify_fail("你現在真氣不足，難以施展" + name() + "。\n" NOR);

        if( query("neili", me)<5000 )
                return notify_fail("你現在內力不夠，難以施展" + name() + "。\n" NOR);

        if( BUFF_D->check_buff(me, "lbwb-shen") )
                return notify_fail("你已經運起" + name() + "。\n" NOR);

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "lbwb_shen")) > 0 )
                        return notify_fail(MAG"神光離合消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        addn("neili", -1000, me);
        me->receive_damage("qi", 0);

        msg = MAG "\n$N" MAG "提起真氣，施展" + name() + MAG "，身形虛晃，神光交錯，離合難分，讓人難以看清所在。\n" NOR;

        buff = ([
                "caster":me,
                "target":me,
                "type"  :"lbwb-shen",
                "attr"  :"bless",
                "name"  :"凌波微步．神光離合",
                "time"  : 30,
                "buff_data":"immortal",
                "buff_msg" :msg,
                "disa_msg" :HIY"你的「神光離合」運功完畢，將內力收回丹田。\n"NOR        ,
        ]);
        BUFF_D->buffup(buff);

        time = 70;
        time -= ABILITY_D->check_ability(me, "cd-lbwb-shen"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        buff =
	([
	        "caster" : me,
	        "target" : me,
	        "type"   : "cooldown",
	        "type2"  : "lbwb_shen",
	        "attr"   : "curse",
	        "name"   : "凌波微步．神光離合",
	        "time"   : time,
	        "buff_msg" : "神光離合消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
	        "disa_msg" : "",
	        "disa_type": 0,
	]);
	BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;

}

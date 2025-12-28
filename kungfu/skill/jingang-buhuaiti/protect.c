// This program is a part of NT MudLIB
// Written by Lonely@nitan.org

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return "金剛不壞"; }
int perform(object me, object target)
{
        mapping buff;
        int duration;
        int skill;
        int time;

        if( query("neili", me) < 100 )
                return notify_fail("你的內力不夠。\n");

        if( me->query_skill("jingang-buhuaiti", 1) < 200 )
                return notify_fail("你的金剛不壞護體神功修為不夠。\n");
        
        if( BUFF_D->check_buff(me, "prtshield") ) 
                return notify_fail("你正在施展類似技藝，無法使用金剛不壞體神功。\n");
                
        if( BUFF_D->check_buff(me, "protect") ) 
                return notify_fail("你正在施展金剛不壞護體神功。\n");

        if( userp(me) ) {
                if( (duration = BUFF_D->get_buff_overtime(me, "jgbht_protect")) > 0 )
                        return notify_fail(MAG"『金剛不壞』消耗心神太甚，還需等待"+duration+"秒。\n"NOR);
        }
        
        skill = me->query_skill("jingang-buhuaiti");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        buff =
                ([
                        "caster":me,
                        "target":me,
                        "type":"prtshield",
                        "type2":"protect",
                        "attr":"bless",
                        "name":"金剛不壞體·金剛不壞",
                        "shield_type":"neili",
                        "shield_amount":skill*10000,
                        "shield_desc":BBLU HIY"卍"NOR CYN" $n"CYN"梵音聲聲，"CYN"周身被"HIY"金光"NOR CYN"籠罩住，$N丈外皆不可進。 "NOR BBLU HIY"卍\n"NOR,
                        "time":  skill/5,
                        "buff_msg": HIY "只聽$N" HIY "高呼佛號，全身肌肉緊縮，霎那間皮膚竟猶如鍍金一般，發出燦燦金光。\n" NOR,
                        //"buff_msg": BBLU HIY"卍"NOR CYN" $n"CYN"魅影懸梭，"CYN"周身被"HIR"血魔化影"NOR CYN"籠罩住，$N"CYN"丈外皆不可進。 "NOR BBLU HIY"卍\n"NOR,
                        "disa_msg": "你的金剛不壞護體神功運行完畢，將內力收回丹田。\n",
                        "disa_type": 1,
                ]);
                                
        BUFF_D->buffup(buff);

        time = skill/5+40;
        time -= ABILITY_D->check_ability(me, "cd-jgbht-protect"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
         
	buff = 
	        ([
	                "caster":me,
	                "target":me,
	                "type":"cooldown",
	                "type2":"jgbht_protect",
	                "attr": "curse",
	                "name":"金剛不壞體·金剛不壞",
	                "time":time,
	                "buff_msg":"『金剛不壞』消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
	                "disa_msg":"",
	                "disa_type": 0,
	        ]);
	        
	BUFF_D->buffup(buff);
        //if( me->is_fighting() ) me->start_busy(2);
        
        return 1;
}

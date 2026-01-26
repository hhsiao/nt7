// This program is a part of NT MudLIB
// 佛光普照 轉世技能
// buddha.c

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
        string msg;
        int skill;
        mapping buff, data;
        int time;

        if( userp(me) && !query("can_exert/yijinjing/buddha", me) )
                return notify_fail("你未得高人指點，不知該如何施展佛光普照。\n");
        /*
        if( query("family/family_name", me) != "少林派" )
                return notify_fail("你不是少林弟子，無法使用佛光普照。\n");
        */

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用佛光普照！\n");

        if( target != me )
                return notify_fail("你只能用易筋經來激發佛光普照。\n");

        if( (skill = me->query_skill("yijinjing", 1)) < 1000 )
                return notify_fail("你的易筋經神功沒有學成，無法使用佛光普照！\n");

        if( me->query_skill("jingang-buhuaiti", 1) < 1000 )
                return notify_fail("你的金剛不壞體神功修為不夠，無法使用佛光普照！\n");

        if( me->query_skill("buddhism", 1) < 1000 )
                return notify_fail("你對禪宗心法的參悟還不夠，無法使用佛光普照！\n");

        if( me->query_skill_mapped("parry") != "jingang-buhuaiti" )
                return notify_fail("你必須激發金剛不壞體，才能使用佛光普照！\n");

        if( query("jingli", me)<2000 )
                return notify_fail("你的真氣不夠。\n");

        if( query("neili", me)<5000 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "buddha") )
                return notify_fail("你正在施展佛光普照。\n");

        if( userp(me) )
                if( (time = BUFF_D->get_buff_overtime(me, "yjj_buddha")) > 0 )
                        return notify_fail(MAG"佛光普照消耗心神太甚，還需等待"+time+"秒。\n"NOR);

        addn("neili", -1000, me);
        me->receive_damage("qi", 0);

        msg = HIY "只聽$N" HIY "高呼佛號，運起佛光普照，霎那間全身竟猶如鍍金一般，發出燦燦金光。\n" NOR;

        data =
        ([
                        "avoid_busy" : 30,
                        "avoid_weak" : 30,
                        "avoid_poison" : 100,
                        "reduce_damage":30,
        ]);
        buff =
        ([
                        "caster": me,
                        "target": me,
                        "type"  : "buddha",
                        "attr"  : "bless",
                        "name"  : "易筋經．佛光普照",
                        "time"  : skill/5,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的易筋經之佛光普照運行完畢，將內力收回丹田，佛光消失。\n",

        ]);

        BUFF_D->buffup(buff);

        time = skill/5+40;
        time -= ABILITY_D->check_ability(me, "cd-yjj-buddha"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd

	buff =
        ([
	                "caster":me,
	                "target":me,
	                "type":"cooldown",
	                "type2":"yjj_buddha",
	                "attr": "curse",
	                "name":"易筋經．佛光普照",
	                "time":time,
	                "buff_msg":"佛光普照消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
	                "disa_msg":"",
	                "disa_type": 0,
        ]);

	BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

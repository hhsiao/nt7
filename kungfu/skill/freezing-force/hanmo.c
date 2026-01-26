// This program is a part of NT MudLIB

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        int time;

        if( !query("yuanshen", me) )
                return notify_fail("你尚未悟道，無法使用寒魔玄力！\n");

        if( target != me )
                return notify_fail("你只能用冰蠶寒功來激發寒魔玄力。\n");

        if( (skill = me->query_skill("freezing-force", 1)) < 1500 )
                return notify_fail("你的冰蠶寒功修為不夠，無法使用寒魔玄力！\n");

        if( me->query_skill("huagong-dafa", 1) < 1500 )
                return notify_fail("你的化功大法修為不夠，無法使用寒魔玄力！\n");

        if( me->query_skill("poison", 1) < 1500 )
                return notify_fail("你對基本毒功的參悟還不夠，無法使用寒魔玄力！\n");

        if( me->query_skill("force", 1) < 1500 )
                return notify_fail("你對基本內功的修為還不夠，無法使用寒魔玄力！\n");

        if( BUFF_D->check_buff(me, "protectshield") )
                return notify_fail("你已經在運起寒魔玄力了。\n");

        if( query("jingli", me)<2000 )
                return notify_fail("你的真氣不夠。\n");

        if( query("neili", me)<5000 )
                return notify_fail("你的內力不夠。\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "freezing_hanmo")) > 0 )
                        return notify_fail(MAG"寒魔玄力消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        skill = me->query_skill("freezing-force", 1);
        addn("neili", -1000, me);
        me->receive_damage("qi", 0);

        message_combatd(HIB "$N" HIB "神色凝重，深吸一口氣，體表瞬間變為靛藍色，$N" HIB "隨之擺出各種奇特的造型舞動著。\n"
                       "隨著那些詭異的舞姿，藍色煙氣四起，在空中竟似顯現無數異樣蠶蟲，在$N身周繞行不止，\n"
                       "四周溫度驟降，只剎那間功夫，空氣似乎都凝結了。\n" NOR, me);

        msg = HIB "這瞬間，$N" HIB "如同毒神附體，使人周身顫慄。\n" NOR;
        data = ([
                "unarmed_damage": skill*10,
                "avoid_freeze"  : 20,
                "add_freeze"    : 20,
                "add_poison"    : 60,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type":"protectshield",
                "type2":"freezing",
                "attr":"bless",
                "name":"冰蠶寒功．寒魔玄力",
                "time":  skill/5,
                "buff_data":data,
                "buff_msg":msg,
                "shield_type":"neili",
                "shield_amount":skill*10000,
                "shield_desc":HIB"$n身邊泛起一層寒氣，將$N攻擊阻在其外。\n"NOR,
                "disa_msg": HIB "$N" HIB "身形一滯，略顯蹣跚，將冰蠶寒魔玄力收回丹田，"
                                "隨著真氣凝成的蠶蟲納入體內，\n$N" HIB"的體色恢復正常，周圍的寒氣也慢慢散開了。\n" NOR,
                "disa_type" : 1,
/*
                "shield_desc":HIW"$n"HIW"一觸$N"HIW"衣衫，忽然全身大震，如遭電擊。\n"NOR,
	        "shield_amount":skill,
	        "shield_type":"jing",
*/
        ]);
        BUFF_D->buffup(buff);

        buff =
        ([
                "caster":me,
                "target":me,
                "type":"damageshield",
                "att":"bless",
                "name":"冰蠶寒功．寒魔玄力",
                "buffup_name":"backfire",
                "buffup_type":"all",
                "buffup_ratio": 35,
                "buffup_msg":WHT"一陣錐心刺骨的寒冷沁進了$n"NOR+WHT"心中，$n"NOR+WHT"不由打了一個寒顫。\n"NOR,
                "time":skill/5,
                "buff_msg":WHT"$N"NOR+WHT"身法乍變，臉若冰霜，投足間陣陣冷風翻卷，刺骨凝寒。\n"NOR,
        ]);
        BUFF_D->buffup(buff);

        time = skill/5+40;
        time -= ABILITY_D->check_ability(me, "cd-freezing-hanmo"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd
        buff =
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "freezing_hanmo",
                "attr"   : "curse",
                "name"   : "冰蠶寒功．寒魔玄力",
                "time"   : time,
                "buff_msg" : "寒魔玄力消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        //if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

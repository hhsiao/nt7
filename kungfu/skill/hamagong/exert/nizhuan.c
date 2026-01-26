// This program is a part of NITAN MudLIB
// nizhuan.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object weapon;
        int skill;
        string msg;
        mapping buff, data;
        int time;

        if( userp(me) && !query("yuanshen", me) )
                return notify_fail("你還沒有悟道，無法施展逆轉九陰。\n");

        /*
        if( query("family/family_name", me) != "歐陽世家" )
                return notify_fail("你不是歐陽世家弟子，無法使用。\n");
        */

        if((int)me->query_skill("hamagong", 1) < 1000)
                return notify_fail("你的蛤蟆功不夠嫻熟，不會逆轉九陰。\n");

        if( query("neili", me)<500 )
                return notify_fail("你的內力不夠。\n");

        if( query("jingli", me)<500 )
                return notify_fail("你的精力不夠。\n");

        if( BUFF_D->check_buff(me, "hmg_nizhuan") )
                return notify_fail("你已經逆運了九陰。\n");

        if( userp(me) )
        {
                if( (time = BUFF_D->get_buff_overtime(me, "hmg_nizhuan2")) > 0 )
                        return notify_fail(MAG"神光離合消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        skill = me->query_skill("force");
        msg = HIB "$N" HIB "雙手撐地，口中發出一連竄低喉聲，一股股內勁勃發使$N" HIB "雙足離地，呈頭下足上之勢。。\n" NOR;

        //tell_object(me, HIW "你感覺體內蛤蟆功隨九陰逆轉，好像有股巨大的力量要崩發出來一樣。\n" NOR);

        data = ([
                "ap_power"  : 50,
                "add_damage": 100,
                "attack"    : skill,
                "defense"   : skill,
                "avoid_weak": 50,
                "dispel_poison": skill / 3,
                "reduce_poison": 15,
                "str"       : skill/4,
        ]);

        addn("neili", -300, me);
        addn("jingli", -50, me);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "hmg_nizhuan",
                "attr"  : "bless",
                "name"  : "蛤蟆功．逆轉九陰",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你逆轉九陰運功過久，經脈又漸漸復原。\n",

        ]);
        BUFF_D->buffup(buff);

        time  = 40;
        time -= ABILITY_D->check_ability(me, "cd-hmg-nizhuan"); // ab門派減cd
        time -= ABILITY_D->check_ability(me, "reduce_cd", 2); // talent減cd

        buff =
        ([
                "caster" : me,
                "target" : me,
                "type"   : "cooldown",
                "type2"  : "hmg_nizhuan2",
                "attr"   : "curse",
                "name"   : "蛤蟆功．逆轉九陰",
                "time"   : time,
                "buff_msg" : "逆轉九陰消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                "disa_msg" : "",
                "disa_type": 0,
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

// This program is a part of NITAN MudLIB
// Written by Lonely@nitan.org
// protect.c 提高靈鷲宮的威力

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        int skill;
        string msg;
        mapping buff;
        int time;

        if( target != me )
                return notify_fail("你只能用八荒六合唯我獨尊來提升自己的防禦。\n");

        if( BUFF_D->check_buff(me,"prtshield")
                || BUFF_D->check_buff(me,"protect") )
                return notify_fail("你已經在運用類似的武功了。\n");

        if( query("neili", me) < 150 )
                return notify_fail("你的內力不夠。\n");

        if( (int)me->query_skill("bahuang-gong", 1) < 100 )
                return notify_fail("你的八荒六合唯我獨尊修為不夠。\n");

        if( userp(me) ) {
                if( (time = BUFF_D->get_buff_overtime(me, "bhg_protect")) > 0 )
                        return notify_fail(MAG"八荒六合功的唯我獨尊神功消耗心神太甚，還需等待"+time+"秒。\n"NOR);
        }

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);


        msg = HIW "$N" HIW "身子一晃，全身周圍形成一層層罡氣，罡氣逼人！\n" NOR;

        buff =
                ([
                        "caster":me,
                        "target":me,
                        "type":"prtshield",
                        "type2":"protect",
                        "attr":"bless",
                        "name":"八荒六合功．唯我獨尊",
                        "shield_type":"neili",
                        "shield_amount":skill*150,
                        "shield_desc":WHT"$n身邊泛起一層層罡氣，將$N攻擊阻在其外。\n"NOR,
                        "time":  skill/5,
                        "buff_msg": msg,
                        "disa_msg": "你的八荒六合唯我獨尊運行完畢，將內力收回丹田。\n",
                        //"disa_type": 1,
                ]);

        BUFF_D->buffup(buff);

        time = skill/5+30;
        time -= ABILITY_D->check_ability(me, "cd-bhg-protect"); // ab門派減cd

        buff =
                ([
                        "caster" : me,
                        "target" : me,
                        "type"   : "cooldown",
                        "type2"  : "bhg_protect",
                        "attr"   : "curse",
                        "name"   : "八荒六合功．唯我獨尊",
                        "time"   : time,
                        "buff_msg" : "八荒六合功的唯我獨尊神功消耗心神太甚，還需等待"+time+"秒方可再次施展。\n",
                        "disa_msg" : "",
                        "disa_type": 0,
                ]);
        BUFF_D->buffup(buff);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

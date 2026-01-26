// powerup.c 海天一嘯

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        int delta;

        if (target != me)
                return notify_fail("你只能用怒海狂濤來提升自己的戰鬥力。\n");

        if( query("gender", me) != "男性"  )
                return notify_fail("你不具有男性的陽剛之氣，無法使用海天一嘯。\n");
        if( query("neili", me)<100 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "nhkt_haixiao") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");
        addn("neili", -100, me);
        me->receive_damage("qi", 0);

        msg = HIW "$N" HIW "仰天長嘯，氣勢如山洪爆發，丹田內力迅速遊遍全身！！\n" NOR;

        if( query("can_perform/surge-force/new", me) ) skill *= 3;

        delta = ABILITY_D->check_ability(me, "power-nhkt-haixiao"); // 門派ab
        if( delta ) skill += skill*delta/100;
        data = ([
                "attack" : skill*2/5,
                "defense": skill*2/5,
                "damage":skill,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "nhkt_haixiao",
                "attr"  : "bless",
                "name"  : "怒海狂濤．海天一嘯",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的怒濤潮湧運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(3);
        return 1;
}

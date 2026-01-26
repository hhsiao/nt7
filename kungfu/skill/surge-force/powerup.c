// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;

        if (target != me)
                return notify_fail("你只能用怒濤潮湧提升自己的戰鬥力。\n");

        if( query("neili", me)<500 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "powerup") || query_temp("surge_powerup",me))
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("force");

        addn("neili", -200, me);
        me->receive_damage("qi", 0);

        msg = HIC "$N" HIC"一聲長嘯，激起一陣狂風，氣"
                        "浪翻翻滾滾，向兩旁散開。\n霎時之間，便"
                        "似長風動起，氣雲聚合，天地渺然，有如海"
                        "浪滔滔。\n" NOR;

        if (query("can_perform/surge-force/new", me))skill *= 3;

        data = ([
                "attack" : skill*2/5,
                "defense": skill*2/5,
                "unarmed_damage":skill,
                "armor"  : skill/3,
        ]);
                set_temp("surge_powerup",1,me);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me,
                              skill :), skill);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "powerup",
                "attr"  : "bless",
                "name"  : "怒海狂濤．戰神",
                "time"  : skill,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的怒濤潮湧運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if (me->is_fighting()) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int count)
{
        delete_temp("surge_powerup", me);
}

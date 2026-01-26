// This program is a part of NITAN MudLIB
// huaxue.c

#include <ansi.h>

#define HUAXUE "「" HIR "神刀化血" NOR "」"

inherit F_SSERVER;

int exert(object me, object target)
{
        object weapon;
        string msg;
        int skill,damage;
        mapping buff, data;
        int delta;

        if (target != me)
                return notify_fail("你只能用蚩尤狂戰決來提升自己的戰力。\n");

        if( BUFF_D->check_buff(me, "atkup") )
                return notify_fail("你已經在運功中了。\n");

        /*
        if (! me->is_fighting())
                return notify_fail(HUAXUE + "只能在戰鬥中使用。\n");
        */

        if( query("neili", me)<200 )
                return notify_fail("你的真氣不夠！\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的蚩尤狂戰決修為不夠，不能使用" + HUAXUE + "！\n");

        weapon=query_temp("weapon", me);

        if( !objectp(weapon) || query("skill_type", weapon) != "blade" )
                return notify_fail("你沒有裝備刀，難以施展" + HUAXUE + "。\n");

        msg = HIR "$N" HIR "凝神閉目，右手持刀，左手順著" + weapon->name() +
              HIR "刀刃一抹，鮮血頓時將" + weapon->name() + HIR "染紅。\n待到$N"
              HIR "雙目睜開，頓時殺氣沖天！\n" NOR;

        skill = (int)me->query_skill("moshen-xinfa", 1) / 2 + (int)me->query_skill("chiyou-kuangzhanjue", 1);
        damage = (int)me->query_skill("force") * 2;
        delta = ABILITY_D->check_ability(me, "da_power-cykzj-huaxue"); // 門派ab
        if( delta )
        {
             skill += skill*delta/100;
             damage += damage*delta/100;
        }
        addn("neili", -150, me);
        me->receive_damage("qi", 0);

        data = ([
                "damage" : damage,
                "blade"  : skill,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "atkup",
                "attr"  : "bless",
                "name"  : "蚩尤狂戰決．神刀化血",
                "time"  : skill/2,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的蚩尤狂戰決之神刀化血運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

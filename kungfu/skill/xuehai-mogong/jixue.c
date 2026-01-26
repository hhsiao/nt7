// jixue.c 血海魔功祭血大法

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        mapping buff, data;
        object weapon;
        string msg;
        int skill;
        int delta;

        if( BUFF_D->check_buff(me, "xhmg_jixue") )
                return notify_fail(HIG"你已經運起祭血大法了。\n");

        if (! me->is_fighting())
                return notify_fail("「祭血大法」只能在戰鬥中使用。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的真氣不夠！\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的血海魔功的修為不夠，不能使用祭血大法！\n");

        msg = HIR "$N" HIR "使出血海魔功「祭血大法」，剎時間臉色變得"
              "血紅，"HIR "$N" HIR "忽地咬破舌尖，噴出一口鮮血！\n" NOR;

        skill = (int)me->query_skill("xuehai-mogong", 1);

        delta = ABILITY_D->check_ability(me, "ap_power-xhmg-jixue"); // 門派ab
        if( delta ) skill += skill*delta/100;
        if( query("qi", me)>query("max_qi", me)*6/10 )
        {
                data = ([
                        "damage": skill*20,
                        "unarmed_damage": skill*20,
                ]);

                buff = ([
                        "caster": me,
                        "target": me,
                        "type"  : "xhmg_jixue",
                        "attr"  : "bless",
                        "name"  : "血海魔功．祭血大法",
                        "time"  : skill/10,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的祭血大法運行完畢，將內力收回丹田。\n",

                ]);
                BUFF_D->buffup(buff);
                addn("neili", -150, me);
                me->receive_damage("qi",query("max_qi", me)/2);
                return 1;
        } else
                msg = HIR "$N" HIR "發現自己氣力不濟，沒能提起祭血大法。\n" NOR;

        message_combatd(msg, me);
        return 1;
}

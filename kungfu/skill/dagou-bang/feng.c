// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string name() { return HIG "封字訣" NOR; }

int perform(object me, object target)
{
        object weapon;
        string wp;
        int skill;
        int fmsk = me->query_skill("bixue-danxin", 1);
        mapping buff, data;
        string msg;

        if (! target) target = offensive_target(me);

        if( BUFF_D->check_buff(me, "parryup") )
                return notify_fail("你現在正在施展" + name() + "。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "staff" )
                return notify_fail("你使用的武器不對，難以施展" + name() + "。\n");

        skill = me->query_skill("dagou-bang", 1);

        if (skill < 120)
                return notify_fail("你打狗棒法不夠嫻熟，難以施展" + name() + "。\n");

        if (me->query_skill_mapped("staff") != "dagou-bang")
                return notify_fail("你沒有激發打狗棒法，難以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 180)
                return notify_fail("你的內功火候不足，難以施展" + name() + "。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在的真氣不夠，難以施展" + name() + "。\n");

        wp = weapon->name();

        msg = HIG "$N" HIG "使出打狗棒法「" HIY "封"
                        HIG "」字訣，手中" + wp + HIG "疾速舞"
                        "動，幻出許許棒影護住周身。\n" NOR;

        addn("neili", -150, me);
        me->receive_damage("qi", 0);
        
        data = ([
                "defense": skill / 3 + fmsk / 5,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "parryup",
                "attr"  : "bless",
                "name"  : "打狗棒法·封字訣",
                "time"  : skill/2,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的封字訣施展完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}
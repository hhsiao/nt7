// This program is a part of NITAN MudLIB
// leidong.c 雷動九天

#include <ansi.h>

inherit F_SSERVER;

string name() { return "雷動九天"; }

int perform(object me, object target)
{
        string msg;
        int improve, skill; 
        object weapon=query("weapon", me);
        mapping buff, data;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("雷動九天只能對戰鬥中的對手使用。\n");

        if( objectp(query_temp("weapon", me)) )
                return notify_fail("你必須空手才能使用雷動九天！\n");

        if ((skill = (int)me->query_skill("poyu-quan", 1)) < 80)
                return notify_fail("你的破玉拳不夠嫻熟，不會使用雷動九天！\n");

        if ((int)me->query_skill("zixia-shengong", 1) < 80)
                return notify_fail("你的紫霞神功不夠高，不能用出雷動九天傷敵。\n");

        if (me->query_skill_prepared("cuff") != "poyu-quan"
                || me->query_skill_mapped("cuff") != "poyu-quan")
                return notify_fail("你現在無法使用「雷動九天」進行攻擊。\n");

        if( query("neili", me)<200 )
                return notify_fail("你現在內力太弱，無法使出雷動九天。\n");

        if( BUFF_D->check_buff(me, "pyq_lei") )
                return notify_fail("你正在使用雷動九天！\n");

        msg = MAG "$N" MAG "使出劈石破玉拳的絕學雷動九天，頓時天空電閃雷鳴！\n" NOR;

        improve=me->query_dex();
        improve+=me->query_str();
        improve /= 15;
        
        data = ([
                "dex": improve,
                "str": improve, 
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "pyq_lei",
                "attr"  : "bless",
                "name"  : "破玉拳·雷動九天",
                "time"  : skill/5,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的雷動九天運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);
        
        addn("neili", -150, me);
        if (! target->is_busy())
                target->start_busy(random((int)me->query_skill("poyu-quan", 1) / 100 + 2));

        return 1;
}

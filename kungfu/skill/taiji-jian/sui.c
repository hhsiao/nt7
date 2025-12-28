// This program is a part of NITAN MudLIB
// sui.c 隨字訣

#include <ansi.h>

string name() { return "隨字訣"; }

inherit F_SSERVER;

int perform(object me, object target)
{
        mapping buff, data;
        object weapon;
        int skill;
        string msg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("「" + name() + "」只能對戰鬥中的對手使用。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "sword" )
                return notify_fail("必須拿劍才能施展「" + name() + "」。\n");

        if ((int)me->query_skill("taiji-jian", 1) < 100)
                return notify_fail("你的太極劍法不夠嫻熟，不會使用「" + name() + "」。\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 80)
                return notify_fail("你的太極神功火候不夠，難以施展「" + name() + "」。\n");

        if( query("neili", me)<query("max_neili", me)/50 )
                return notify_fail("你的內力不夠。\n");

        if( BUFF_D->check_buff(me, "parryup") )
                return notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("taiji-jian");
        msg = HIC "$N使出太極劍法「隨」字訣，劍圈逐漸縮小，手中" + weapon->name() +
              HIC "幻出道道光環，將周身護住。\n" NOR;

        data = ([
                "attack": -skill/6,
                "defense": skill*3,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "parryup",
                "attr"  : "bless",
                "name"  : "太極劍法·隨字訣",
                "time"  : skill/3,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你的隨字訣運行完畢，將內力收回丹田。\n",
                        
        ]);
        BUFF_D->buffup(buff);

        addn("neili", -query("max_neili", me)/50, me);
        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

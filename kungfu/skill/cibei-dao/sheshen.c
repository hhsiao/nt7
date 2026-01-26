// This program is a part of NITAN MudLIB
// sheshen.c 「捨身喂鷹」

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return "捨身喂鷹"; }

int perform(object me)
{
        object weapon;
        int skill;
        string msg;
        mapping buff, data;

        if ((int)me->query_skill("cibei-dao", 1) < 60)
                return notify_fail("你的慈悲刀法不夠嫻熟，不會使用「捨身喂鷹」。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的真氣不夠，無法使用「捨身喂鷹」。\n");

        if( BUFF_D->check_buff(me, "atkup") )
                return notify_fail("你已經在運功中了。\n");

        if( !objectp(weapon=query_temp("weapon", me)) ||
              query("skill_type", weapon) != "blade" )
                return notify_fail("你使用的武器不對。\n");

        skill = me->query_skill("cibei-dao", 1);
        msg = HIR "$N" HIR "使出慈悲刀法「捨身喂鷹」，將渾身的功力都運到" +
              weapon->name() + HIR "上！\n" NOR;

        data = ([
                "attack" : skill/3,
                "defense": -skill/5,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "atkup",
                "attr"  : "bless",
                "name"  : "慈悲刀法．捨身喂鷹",
                "time"  : skill/4,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : "你的捨身喂鷹運行完畢，將內力收回丹田。\n",

        ]);
        BUFF_D->buffup(buff);
        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

// This program is a part of NT MudLIB
// ziqi.c 紫氣東來

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
        object weapon;
        string msg;
        mapping buff, data;
        int d_count, count, qi, maxqi, skill;

        if( BUFF_D->check_buff(me, "damageup")
                || BUFF_D->check_buff(me,"ziqi_donglai") )
                return notify_fail(HIG"你已經在運起紫氣東來了。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的內力還不夠！\n");

        if( (int)me->query_skill("force") < 150)
                 return notify_fail("你的紫霞神功的修為不夠，不能使用紫氣東來! \n");

        // 必須有兵器。加兵器威力
        if( !objectp(weapon=query_temp("weapon", me)) ||
            query("skill_type", weapon) != "sword" )
                return notify_fail("你沒有劍.怎麼用紫氣東來呀? \n");

        msg = MAG "$N" MAG "猛吸一口氣，臉上紫氣大盛！手中的兵器隱隱透出一層紫光。。。\n" NOR;

        qi=query("qi", me);
        maxqi=query("max_qi", me);
        skill = (int)me->query_skill("zixia-shengong", 1);

        if( qi > (maxqi * 0.4) )
        {
                data =
                ([
                        "damage": skill*5,
                        "sword" : skill/10,
                ]);
                buff =
                ([
                        "caster": me,
                        "target": me,
                        "type"  : "damageup",
                        "type2" : "ziqi_donglai",
                        "attr"  : "bless",
                        "name"  : "紫霞神功．紫氣東來",
                        "time"  : skill,
                        "buff_data": data,
                        "buff_msg" : msg,
                        "disa_msg" : "你的紫氣東來運行完畢，紫氣漸漸隱去.。\n",

                ]);
                BUFF_D->buffup(buff);

                addn("neili", -150, me);
        }
        else
        {
                msg = HIR "$N" HIR "拼盡畢生功力想提起紫氣東來，但自己受傷太重，沒能成功!\n" NOR;
                message_combatd(msg, me);
        }

        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

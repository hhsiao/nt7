// This program is a part of NITAN MudLIB
// zong.c

#include <ansi.h>

string name() { return "縱字訣"; }

void remove_effect(object me,int count);

int perform(object me, object target)
{
        mapping buff, data;
        string msg;
        int improve;
        int delta;

        if( (int)me->query_skill("tiyunzong",1) < 120 )
                return notify_fail("你的梯雲縱不夠嫻熟，不會使用「縱字訣」！\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("你的太極神功等級不夠，不能使用「縱字訣」！\n");

        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你的內功不對，不能使用「縱字訣」。\n");

        if( (int)me->query_dex() < 28 )
                return notify_fail("你的身法太低，不能使用「縱字訣」！\n");

        if( (int)me->query_skill("dodge",1) < 120 )
                return notify_fail("你的基本輕功太差，身體笨拙，不能使用「縱字訣」！\n");

        if( query("neili", me)<600 )
                return notify_fail("你的內力太少了，無法使用出「縱字訣」！\n");

        if (me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("你現在激發的輕身數使用「縱字訣」絕技。\n");

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你正在使用梯雲縱的特殊防禦「縱字訣」！\n");

        if( query_temp("zong", me) )
                return notify_fail("你正在使用梯雲縱的特殊防禦「縱字訣」！\n");

        msg = HIY"$N突然深吸一口氣，一抬腿猛的拔高數丈，升勢剛盡，雙腿連續踢出，" +
                        "身體又上升丈許，才有如大鳥般盤旋落下！\n" NOR;

        improve = (int)me->query_skill("dodge")* 10;
        delta = ABILITY_D->check_ability(me, "dp_power-tyz-zong"); // 門派ab
        if( delta ) improve += improve*delta/100;

        data = ([
                "defense": improve,
        ]);
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "attr"  : "bless",
                "name"  : "梯雲縱．縱字訣",
                "time"  : improve/10,
                "buff_data": data,
                "buff_msg" : msg,
                "disa_msg" : HIY"你散去丹田凝聚的內力，混身經脈真氣流動，氣定神閒，精神弈弈。\n"NOR,

        ]);
        BUFF_D->buffup(buff);

        addn("neili", -(350-me->query_skill("tiyunzong",1)/100), me);
        return 1;
}

/*
void remove_effect(object me, int count)
{
        int improve;
        if( !me ) return;
        if( !intp(improve=query_temp("zong", me)))return ;
        if( !me->is_fighting()
        ||  count < 1)
        {
                BUFF_D->debuff(me, "dodgeup", 1);

                delete_temp("zong", me);
                tell_object(me, HIY"你散去丹田凝聚的內力，混身經脈真氣流動，氣定神閒，精神弈弈。\n"NOR);
                tell_room(environment(me), HIY + me->name()+"全身骨頭一陣輕響，散去了混身的功力。\n"NOR,  ({ me }));
                return;
        }
        call_out("remove_effect", 1 , me ,count -1);
}
*/

int help(object me)
{
        write(WHT"\n梯雲縱「縱」字訣："NOR"\n");
        write(@HELP
        武當輕功，當世可謂獨步武林，天下輕功無出其右，臨敵之時使出「縱」字
        訣，可以用來大幅度提升自己的輕功有效等級，增加勝算或逃脫機率。

        要求：  梯雲縱等級 120 以上；
                太極神功等級 120 以上；
                基本輕功等級 120 以上；
                內力 600 以上；
                後天身法 28 以上。
HELP
        );
        return 1;
}

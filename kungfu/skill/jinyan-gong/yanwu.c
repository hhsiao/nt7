// This program is a part of NITAN MudLIB

#include <combat.h>
#include <ansi.h>

inherit F_SSERVER;

string name() { return "鷹飛雁舞"; }

int perform(object me, object target)
{
        string msg;
        int lvl1, amount;
        mapping buff, data;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「鷹飛雁舞」輕功絕技只能對戰鬥中的對手使用。\n");

        if( BUFF_D->check_buff(me, "dodgeup") )
                return notify_fail("你正在運用「鷹飛雁舞」輕功絕技！\n");

        /*
        if( me->query_skill_mapped("force") != "xiantian-gong")
                return notify_fail("你所用的內功與「鷹飛雁舞」輕功絕技運氣方式相悖！\n");
        */

        if( me->query_skill_mapped("dodge") != "jinyan-gong")
                return notify_fail("你所用的身法與「鷹飛雁舞」招式不同，無法使用！\n");

        if( me->query_skill("dodge") < 134 )
                return notify_fail("你的身法修為不夠，還無法施展「鷹飛雁舞」輕功絕技！\n");

        if( me->query_skill("force") < 59 )
                return notify_fail("你的內功修為火候未到，無法施展「鷹飛雁舞」輕功絕技！\n");

        if( query("neili", me)<600 )
                return notify_fail("你的內力不夠，勁力不足以施展「鷹飛雁舞」輕功絕技！\n");

        msg = HIC "$N清嘯一聲，身法陡然加快。$N的身影時如鷹擊長空、時如群雁飛舞，令人眼花撩亂，煞是好看。\n\n" NOR;

        lvl1 = (int)me->query_skill("dodge");
        
        addn("neili", -(lvl1)/3, me);
        
        data = ([
                "dex"    : lvl1/5,
                "defense": lvl1/3,
        ]);

        buff = ([
                "caster": me,
                "target": me,
                "type"  : "dodgeup",
                "attr"  : "bless",
                "name"  : "金雁功·鷹飛雁舞",
                "time"  : lvl1/8,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : HIY "$N身形漸停，深吸一口氣，收回了「鷹飛雁舞」輕功絕技。\n" NOR,
                "disa_type": 1,
                        
        ]);
        BUFF_D->buffup(buff);
        return 1;
}

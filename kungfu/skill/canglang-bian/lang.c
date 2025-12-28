// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit F_SSERVER;
string name() { return "巨浪滔天"; }

int perform(object me, object target)
{
        object weapon;
        int skill;
        mapping buff, data;
        string msg;

        if (! target) target = offensive_target(me);

        if (! target
        ||      ! target->is_character()
        ||      ! me->is_fighting(target))
                return notify_fail("「巨浪滔天」只能對戰鬥中的對手使用。\n");

        if( !objectp(weapon=query_temp("weapon", me) )
        ||      query("skill_type", weapon) != "whip" )
                return notify_fail("你沒有鞭在手，施不出「巨浪滔天」。\n");

        if( query("neili", me)<200 )
                return notify_fail("你的內力不夠！\n");

        if (me->query_skill("canglang-bian", 1) < 200)
                return notify_fail("你的「滄浪鞭法 」未臻高妙境界，無法施出「巨浪滔天」！\n");

        if (me->query_skill("bibo-shengong", 1) < 200)
                return notify_fail("你的碧濤玄功修為不夠，無法施出「滄浪鞭法」！\n");

        if (me->query_skill_mapped("whip") != "canglang-bian")
                return notify_fail("你所用的並非「滄浪鞭法 」，施展不出「巨浪滔天」！\n");

        if( BUFF_D->check_buff(me, "atkup") )
                return notify_fail("你已經在運用類似的武功了。\n");
                
        message_combatd(
                HIR"$N忽然將"+(query("name", query_temp("weapon", me)))+
                HIR"頻頻甩出，"+(query("name", query_temp("weapon", me)))+
                HIR "發出劈啪暴空之聲不絕擾得$n心煩意亂。\n" NOR, me, target);
        msg = HIB "$N的招數萬千，但鞭頭卻總是指向"+target->name()+"的周身要穴，攻擊如巨浪連綿無窮無盡，"
                "令"+target->name()+"只有招架之功卻無還手之力。\n" NOR;

        set_temp("julang", 1, me);

        skill =  ( me->query_skill("canglang-bian") + me->query_skill("dodge") ) / 2;
        addn("neili", -200, me);
        
        data = ([
                "attack" : skill/3,
                "defense": skill/3,
        ]);
        
        buff = ([
                "caster": me,
                "target": me,
                "type"  : "atkup",
                "attr"  : "bless",
                "name"  : "滄浪鞭法·巨浪滔天",
                "time"  : skill/3,
                "buff_data": data,      
                "buff_msg" : msg,
                "disa_msg" : "你慢慢內運內功，把真氣壓下！\n",                      
        ]);
        
        COMBAT_D->do_attack(me,target,query_temp("weapon", me));
        COMBAT_D->do_attack(me,target,query_temp("weapon", me));
        COMBAT_D->do_attack(me,target,query_temp("weapon", me));

        me->start_busy(1+random(2));
        return 1;
}

//  lihua.c 驟雨清荷 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return HIC"驟雨清荷"NOR;}

private int remove_effect(object me, int amount);

int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("「驟雨清荷」只能在戰鬥中使用。\n");
    
        if ((int)me->query_skill("yangjia-qiang", 1) < 150 )
                return notify_fail("你的楊家槍不夠嫻熟，不能真正發揮「驟雨清荷」的威力。\n");
    
        if((int)me->query_skill("spear", 1) < 150 )
                return notify_fail("你的基本內功等級不夠，不能使用「驟雨清荷」。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "spear" )
                return notify_fail("你手中無槍，怎能運用「驟雨清荷」？！\n");
                                
        if (me->query_skill_mapped("spear") != "yangjia-qiang"
         || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("你現在無法使用「神威槍」進行攻擊。\n");
    
        if ((int)me->query("max_neili") < 2500 )
                return notify_fail("你的內力修為太低，不能使用「驟雨清荷」。\n");

        if ((int)me->query("neili") < 1000 )
                return notify_fail("你現在內力太弱，不能使用「驟雨清荷」。\n");

        if ((int)me->query("jingli") < 500 )
                return notify_fail("你現在精力太少，不能使用「驟雨清荷」。\n");

        if(me->query_temp("yjq/qinghe"))
                return notify_fail("你現正在使用「驟雨清荷」。\n");

        if(me->query_temp("yjq/shenwei"))
                return notify_fail("你現正在使用「神威槍」。\n");
                
        if(me->query_temp("yjq/jifeng"))
                return notify_fail("你現正在使用「疾風槍」。\n");

    message_vision(HIM"$N使出楊家槍絕技之「"HIG"驟雨清荷"HIM"」，只見"+weapon->query("name")+HIM"只覺感覺身體輕盈飄逸，瀟灑無比！\n"NOR, me);
        me->start_exert(5+random(2),"「驟雨清荷」");
        me->add("neili", -200);
        me->add("jingli", -500);
        me->start_busy(1+random(2));
    
        skill = me->query_skill("yangjia-qiang", 1);
        me->add_temp("apply/attack",  -skill/5);
        me->add_temp("apply/damage",  -skill/5);
        me->add_temp("apply/parry",  skill/2);
        me->add_temp("apply/dodge",  skill/2);
        me->set_temp("yjq/qinghe", skill);

        call_out("check_fight", 1, me, weapon);
        return 1;
}

void check_fight(object me, object weapon)
{  
        object wep;
        int i;

        if (!me) return;
        wep = me->query_temp("weapon");  
        if( !me->is_fighting()
         || !living(me)
         || me->is_ghost()
         || me->query_skill_mapped("spear") != "yangjia-qiang" 
         || me->query_skill_mapped("parry") != "yangjia-qiang" 
         || !wep
         || weapon != wep ){
       i = me->query_temp("yjq/qinghe");
        me->add_temp("apply/attack", i/5);
        me->add_temp("apply/damage", i/5);
        me->add_temp("apply/parry",  -i/2);
        me->add_temp("apply/dodge",  -i/2);
           me->delete_temp("yjq/qinghe");
           if(living(me) && !me->is_ghost())
              message_vision(HIW"$N一套「驟雨清荷」使完，感覺到從沒有過的飄逸。\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
   write(YEL"\n楊家槍「"HIG"驟雨清荷"YEL"」："NOR"\n");
   write(@HELP
   指令：perform qinghe

   要求：楊家槍150級，
         基本槍法150級，
         最大內力 2500 以上，
         當前內力 2000 以上，
         當前精力 500 以上，
         激發楊家槍為招架。
HELP
   );
   return 1;
}

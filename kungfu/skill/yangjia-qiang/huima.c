//  huima.c 回馬槍 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

string perform_name() {return WHT"回馬槍"NOR;}

int perform(object me,object target)
{
    object weapon;
    int i;
    i = me->query_skill("yangjia-qiang", 1) /3;
    if( !target ) target = offensive_target(me);
     
    if(!objectp(target) || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("「回馬槍」只能對戰鬥中的對手使用。\n");

    if((int)me->query_skill("force", 1) < 250 )
                return notify_fail("你的基本內功不夠嫻熟，無法支持「回馬槍」。\n");

    if( (int)me->query_skill("yangjia-qiang", 1) < 250 ) 
                return notify_fail("你的槍法還未練成，不能使用「回馬槍」！\n");

    if((int)me->query_skill("spear", 1) < 250 )
                return notify_fail("你的基本槍法不夠嫻熟，不能在劍招中使用「回馬槍」。\n");

    if((int)me->query_skill("dodge", 1) < 250 )
                return notify_fail("你的基本輕功不夠嫻熟，不能使用「回馬槍」。\n");

    if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "spear"
        || me->query_skill_mapped("spear") != "yangjia-qiang"
        || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("你手裡無槍，如何使用「回馬槍」？\n");
                
    if((int)me->query("max_neili") < 8000 )
                return notify_fail("你的內力修為不夠，不能使用「回馬槍」！\n");

    if((int)me->query("neili") < 3000 )
                return notify_fail("你現在真氣不足，不能使用「回馬槍」！\n");

    if((int)me->query("jingli") < 1000 )
                return notify_fail("你現在太累了，不能使用「回馬槍」！\n");
      
message_vision(HIB"\n$N忽然縱身躍起，竟使出楊家槍之"YEL"「回馬槍」"HIB"絕技，只見槍鋒到處迸發出一陣漩渦，讓四周之人膽顫心驚！\n"NOR, me,target);

    me->start_perform(3,"「回馬槍」");
    me->add("neili", -800);
    me->add("jingli",-500);
    me->set_temp("yjq/huima",1);

    me->add_temp("apply/attack", i);
    me->add_temp("apply/damage",i);
    
	target->set_temp("must_be_hit",1);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
   target->delete_temp("must_be_hit");
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
   
   me->add_temp("apply/damage", -i);
   me->add_temp("apply/attack", -i);
    me->delete_temp("yjq/huima");
    me->start_busy(1);
    target->start_busy(1);
    return 1;
}

int help(object me)
{
   write(YEL"\n楊家槍「"HIG"回馬槍"YEL"」："NOR"\n");
   write(@HELP
   指令：perform huima

   要求：楊家槍250級，
         基本槍法250級，
         最大內力 8000 以上，
         當前內力 3000 以上，
         當前精力 1000 以上，
         激發楊家槍為招架。
HELP
   );
   return 1;
}
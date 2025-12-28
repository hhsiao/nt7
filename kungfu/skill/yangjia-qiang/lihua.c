//  lihua.c 暴雨梨花 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

 string perform_name(){ return HIG"暴雨梨花"NOR; }
int perform(object me, object target)
{
        object weapon, ob;
        int speed, attack, lv, damage;

        lv = (int)me->query_skill("yangjia-qiang", 1); 
        damage = lv + random(lv/2) + (int)me->query_skill("spear",1);
                      attack = lv + random(lv/2);
                         speed = me->query_skill("spear")/80;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
	               return notify_fail("「暴雨梨花」只能對戰鬥中的對手使用。\n");

        if( me->query_temp("yjq/lihua"))
	               return notify_fail("你正在使用「暴雨梨花」！\n");
	               
	      if( me->query_temp("lihua"))
	               return notify_fail("你剛使用過「暴雨梨花」，再調整下內息吧！\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
          || weapon->query("skill_type") != "spear"
          || me->query_skill_mapped("spear") != "yangjia-qiang"
          || me->query_skill_mapped("parry") != "yangjia-qiang")
                 return notify_fail("你手裡無槍，如何使用「暴雨梨花」？\n");
                 
        if((int)me->query("max_neili") < 15000 )
               return notify_fail("你的內力修為不夠，無法使用「暴雨梨花」！\n");

        if( (int)me->query("neili") < 10000 )
	             return notify_fail("你的內力不夠！\n");

        if( me->query_skill("yangjia-qiang", 1) < 450 )
	              return notify_fail("你的「楊家槍」等級不夠，無法使用「暴雨梨花」！\n");
	               
        if( me->query_skill("spear", 1) < 400 )
                return notify_fail("你的「基本槍法」等級不夠，無法使用「暴雨梨花」！\n");
                 
        if( (int)me->query_con() < 22 )
		            return notify_fail("你的先天根骨不足，「暴雨梨花」絕技對你來說幾乎是太難了。\n");

        message_vision(HIC "\n$N突感渾身氣力充沛力道無比，將"+weapon->query("name")+HIC"後柄突然舉高握於手心，猛然向$n胸口如暴風驟雨般突刺\n"+
                            "只見"+weapon->query("name")+HIC"槍鋒到處突顯出宛如"HIG"暴雨梨花"HIC"般氣旋，其槍鋒勢不可當,使人目不暇接，堪當楊家槍之絕旨！"NOR"\n" NOR, me,target);
        me->start_perform(3+random(5), "「暴雨梨花」");
        ob = me->select_opponent();
        me->set_temp("lihua",4);
        me->set_temp("yjq/lihua");
        call_out("checking", 1, me, target);
        return 1;
}

  void checking(object me, object target, int speed, int damage, int attack)
{

        object weapon;
	      if ( !objectp( me ) ) return;
        weapon = me->query_temp("weapon");

        if (!objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "spear") {
		       tell_object(me, "\n你手中無槍，當下停止了暴雨梨花的架勢。\n" NOR);
		       me->delete_temp("lihua");
		       me->delete_temp("yjq/lihua");
		       return;
	}

        if ( me->query_temp("lihua") ==4)
      message_vision(HIM"\n只見"+weapon->name()+HIM"陡然迸發，槍鋒氣旋直刺$n，「"HIG"暴雨梨花"HIM"」果然天下聞名，速度快的迅無絕倫，無人可擋！\n" NOR, me,target);
	{
		me->add_temp("apply/attack",  (int)me->query_skill("yangjia-qiang", 1)/2);
		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
		 COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		    me->add_temp("apply/attack", -(int)me->query_skill("yangjia-qiang", 1)/2);
		 me->add("neili", -500);
		 me->start_busy(1);
		target->start_busy(1+random(1));
		}
		
		if ( me->query_temp("lihua") ==4 )
	    message_vision(HIB"\n忽然一道絢彩藍色光線延著"+weapon->name()+HIB"向槍尖疾去，$N大聲喝道：「"+target->name()+HIB"，小心！」\n" NOR, me,target);
           damage = (int)me->query_skill("yangjia-qiang", 1)+ (int)me->query_skill("spear", 1);
           damage = random(damage)*2 + random(damage);
        {       
    me->start_busy(1+random(2));      	  
		target->start_busy(1+random(1));
		me->add_temp("apply/attack",  (int)me->query_skill("yangjia-qiang", 1)/2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
		   me->add_temp("apply/attack", -(int)me->query_skill("yangjia-qiang", 1)/2);
		target->add("neili", -damage/10);
		   me->add("neili", -400);    
       message_vision(RED"\n$n只覺身體一涼，"+weapon->name()+RED"已經自$N胸口對穿過去，鮮血蹦的滿地！\n"NOR,me,target);
        }		
	
    if ( me->query_temp("lihua") !=3 )
    	message_vision(WHT"\n$N將全身內力貫穿於"+weapon->name()+WHT"只見剛才還是如暴雨梨花般的突刺，又猛然轉換招式楊家槍之"HIY"「回馬槍」"WHT"絕技！\n" NOR, me,target);
    {        
    me->add("neili", -500);
    me->add("jingli",-500);
    me->set_temp("yjq/huima",1);

    me->add_temp("apply/attack",  (int)me->query_skill("yangjia-qiang", 1) /3 );
    me->add_temp("apply/damage", (int)me->query_skill("yangjia-qiang",1) /3 );
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"),3);
    me->add_temp("apply/damage", -(int)me->query_skill("yangjia-qiang",1) /3 );
    me->add_temp("apply/attack",   -(int)me->query_skill("yangjia-qiang", 1) /3 );
    
    me->delete_temp("yjq/huima");
    me->start_busy(1+random(1));
    me->delete_temp("yjq/lihua");
      call_out("lihua_finish", 6+random(4), me);
		}
	        
	      	    
 }
 
void lihua_finish(object me,object target)
{
        object weapon;
	      if ( !objectp( me ) )
		       return;
        weapon = me->query_temp("weapon");
       message_vision(HIG"\n$N一套「暴雨梨花」使完，"+weapon->name()+HIG"速度漸漸慢了下來。\n"NOR, me);
        me->delete_temp("lihua");
        me->start_busy(2);     
}

int help(object me)
{
   write(YEL"\n楊家槍「"HIG"暴雨梨花"YEL"」："NOR"\n");
   write(@HELP
   指令：perform lihua

   要求：楊家槍450級，
         基本槍法450級，
         最大內力 15000 以上，
         當前內力 10000 以上，
         當前精力 6000 以上，
         激發楊家槍為招架。
HELP
   );
   return 1;
}
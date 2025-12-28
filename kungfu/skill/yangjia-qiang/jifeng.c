//  lihua.c 疾風槍 
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>

inherit F_SSERVER;

string perform_name() {return MAG"疾風槍"NOR;}

private int remove_effect(object me, int amount);

int perform(object me)
{
        object weapon = me->query_temp("weapon");  
        int skill;
    
        if(!me->is_fighting() )
                return notify_fail("「疾風槍」只能在戰鬥中使用。\n");
    
        if ((int)me->query_skill("yangjia-qiang", 1) < 350 )
                return notify_fail("你的楊家槍不夠嫻熟，不能真正發揮「疾風槍」的威力。\n");
    
        if((int)me->query_skill("spear", 1) < 350 )
                return notify_fail("你的基本內功等級不夠，不能使用「疾風槍」。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
         || weapon->query("skill_type") != "spear" )
                return notify_fail("你手中無槍，怎能運用「疾風槍」？！\n");
                                
        if (me->query_skill_mapped("spear") != "yangjia-qiang"
         || me->query_skill_mapped("parry") != "yangjia-qiang")
                return notify_fail("你現在無法使用「神威槍」進行攻擊。\n");
    
        if ((int)me->query("max_neili") < 6000 )
                return notify_fail("你的內力修為太低，不能使用「疾風槍」。\n");

        if ((int)me->query("neili") < 3000 )
                return notify_fail("你現在內力太弱，不能使用「疾風槍」。\n");

        if ((int)me->query("jingli") < 2000 )
                return notify_fail("你現在精力太少，不能使用「疾風槍」。\n");

        if(me->query_temp("yjq/jifeng"))
                return notify_fail("你現正在使用「疾風槍」。\n");

        if(me->query_temp("yjq/shenwei"))
                return notify_fail("你現正在使用「神威槍」。\n");
                
        if(me->query_temp("yjq/qinghe"))
                return notify_fail("你現正在使用「驟雨清荷」。\n");

    message_vision(HIC"$N融合貫通武學，使出楊家槍絕技之「"MAG"疾風槍"HIC"」，只見"+weapon->query("name")+HIC"招數凌厲，招數猶如幻影般朝發夕至！\n"NOR, me);
        me->start_exert(2+random(2),"「疾風槍」");
        me->add("neili", -500);
        me->add("jingli", -300);
        me->start_busy(1+random(2));
    
        skill = me->query_skill("yangjia-qiang", 1);
        skill = skill /3;
        me->add_temp("apply/attack",  skill);
        me->set_temp("double_attack",1);
        me->set_temp("yjq/jifeng", skill);

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
       i = me->query_temp("yjq/jifeng");
           me->add_temp("apply/attack", -i);
           me->delete_temp("double_attack");
           me->delete_temp("yjq/jifeng");
           if(living(me) && !me->is_ghost())
              message_vision(HIW"$N一套「疾風槍」使完，臉上不由凸現一股豪氣。\n"NOR, me);
           return;
        } 
        call_out("check_fight", 1, me, weapon);
}

int help(object me)
{
   write(YEL"\n楊家槍「"HIG"疾風槍"YEL"」："NOR"\n");
   write(@HELP
   指令：perform jifeng
   
   大幅提高攻擊速度。

   要求：楊家槍350級，
         基本槍法350級，
         最大內力 5000 以上，
         當前內力 3000 以上，
         當前精力 2000 以上，
         激發楊家槍為招架。
HELP
   );
   return 1;
}

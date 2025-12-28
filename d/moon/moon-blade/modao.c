 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra, step,bonus,lvl,str;
        object weapon;
            weapon=me->query_temp("weapon");
        lvl = me->query_skill("moon-blade",1);
        if ( me->query("class")!= "bandit")
			return notify_fail("你的圓月魔刀已經失去了功效。\n");
        if ( lvl < 50)
                return notify_fail("你的［圓月魔刀］還不夠純熟！\n");
        step = me->query_skill("demon-steps",1);

        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "demon-steps")
                return notify_fail("『圓月·魔刀』需要如意人魔連環八步的配和！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『圓月·魔刀』只能對戰鬥中的對手使用。\n");
          if(NATURE_D->is_day_time()) {
                extra= me->query_skill("blade");
   } else {
                extra= me->query_skill("blade")*2;
        }
        bonus = me->query("combat_exp")/1000*extra/8000;
 if (bonus>extra*4) bonus=extra*4;
 	 str = 0;
        if (me->query_skill("moon-blade",1)>500) str = me->query_skill("moon-blade",1)/4;
        			if (me->query_skill("moon-blade",1)>1000) str = me->query_skill("moon-blade",1)/2;
        			 	if (me->query_skill("moon-blade",1)>2000) str = me->query_skill("moon-blade",1);
        			 me->add_temp("apply/skill_str",str);
        if (lvl <100) {
  me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra+bonus);
        msg = HIC"『圓月·魔刀』"HIW"--$N手中的"NOR + weapon->query("name")+ NOR HIW"猶如圓月當空，凌厲的刀影化作一道道月光刺向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

  me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra-bonus);
       me->start_busy(1);
   }
        else {
  me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra+bonus);

        msg = HIC"『圓月』"NOR WHT"--$N手中的"NOR + weapon->query("name")+ NOR WHT"猶如圓月當空，凌厲的刀影化作一道道月光刺向$n！" NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = RED"『魔刀』"NOR WHT"--突然$N刀鋒一轉，"NOR + weapon->query("name")+ NOR WHT"從一個不可思議的角度劃出一道怪異的鋒芒，$n"NOR WHT "竟然沒有看清這刀的變化！" NOR;
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra-bonus);
        me->start_busy(2);

}
        me->add_temp("apply/skill_str",-str);
        return 1;
}

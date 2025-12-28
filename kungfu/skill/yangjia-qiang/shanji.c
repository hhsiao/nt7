// pi.c 打狗槍法--閃擊
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return RED"閃擊"NOR; }
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你現在沒空！！\n");
        if( (int)me->query_skill("yangjia-qiang",1) < 50)
        return notify_fail("你目前功力還使不出「閃擊」。\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
			return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("neili") < 500 )
    return notify_fail("你的內力不夠。\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［閃擊］只能對戰鬥中的對手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("yangjia-qiang",1) *2 ;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = RED  "$N手中的"+ weapon->name() +"幻出一環槍影，"+weapon->name() +"劃破長空，向$n瘋狂劃去！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
 me->start_perform(3+random(2), "「閃擊」");

	me->start_busy(2);
	return 1;
}

int help(object me)
{
   write(YEL"\n楊家槍「"HIG"閃擊"YEL"」："NOR"\n");
   write(@HELP
   指令：perform shanji

   要求：楊家槍50級，
         基本槍法50級，
         當前內力 500 以上，
         當前精力 100 以上，
HELP
   );
   return 1;
}

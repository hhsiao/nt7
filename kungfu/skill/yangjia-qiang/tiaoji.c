// tiao.c 挑擊
//Created by Redhat@Sjmud 2009/4/7

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string perform_name(){ return HIY"挑擊"NOR; }
int perform(object me, object target)
{
	string msg;
	object tweapon, weapon;
	int ap, dp;

	me->clean_up_enemy();
	target = me->select_opponent();

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("「挑擊」只能對戰鬥中的對手使用。\n");

	weapon = me->query_temp("weapon");
	tweapon = target->query_temp("weapon");

	if( !weapon
	 || weapon->query("skill_type") != "spear"
	 || me->query_skill_mapped("spear") != "yangjia-qiang" )
		return notify_fail("你現在無法使用「挑擊」。\n");

	if( !tweapon )
		return notify_fail("對方沒有使用任何兵器，你無法使用「挑擊」。\n");

	if((int)me->query_skill("yangjia-qiang", 1) < 120 )
		return notify_fail("你的楊家槍還不夠嫻熟，不會使用「挑擊」。\n");

	if((int)me->query("neili") < 2000 )
		return notify_fail("你的內力不夠！\n");

	if( (int)me->query_str() < 25 )
		return notify_fail("你的先天臂力不足，無法使用「挑擊」。\n");

	if( me->query_skill_mapped("parry") != "yangjia-qiang"
	&& me->query_skill_mapped("parry") != "yangjia-qiang" )
                return notify_fail("你需要激發招架為楊家槍，方能使用「挑擊」。\n");

	if ( weapon )
		msg = HIR"$N右手搭槍，將手中"+weapon->name()+NOR+HIR"向上挑住$n兵器，試圖以己之強大臂力打掉$n兵器。\n"NOR;

	me->start_perform(3, "挑擊");

	ap = me->query("combat_exp")/1000 * me->query_str(1);
	dp = target->query("combat_exp")/1000 * target->query_str(1);

	if( random(ap + dp) > dp ) {
		int move_flag = 0;
		if(tweapon->is_owner(target)) move_flag=1;
		msg += HIY"$n只感"+tweapon->name()+HIY"壓力卻越來越重，再也無法控制，一個把握不住，手中兵器被飛了出去。\n"NOR;
		target->add_busy(1+random(2));
		me->add("neili",-300);

		if (move_flag==0 && random(2)!=1 && tweapon->query("imbued") < 3 && tweapon->move(environment(me))){
			msg += HIY"$n的兵器被$N的槍技挑擊，剎那間"+tweapon->name()+HIY"已被$N已被挑出$n控制。\n"NOR;
		}
		else {
			msg += HIY"$n被$N手中"+weapon->name()+HIY"被$N槍技壓制，無法控制，只能將"+tweapon->name()+HIY"放下。\n"NOR;
			tweapon->unequip();
			tweapon->move(environment(me));
		}
	}
	else {
		me->add("neili",-200);
              msg += MAG"$n借力運功，"+tweapon->name()+CYN"隨"+weapon->name()+CYN"劃出一道光環，將$N挑擊化於無形！\n"NOR;

	}
	me->start_busy(random(2));
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
	write(HBMAG"\n楊家槍之「挑擊」："NOR"\n");
	write(@HELP
	楊家槍絕招數獨特，運用於其長槍遠距離攻擊之優勢，
	可挑掉對方武器，使其無法使用其武器。
	perform tiaoji

	要求：	當前內力 2000 以上；
		楊家槍等級 100 以上；
		激發招架為楊家槍；
		對手若手無兵器，則無效果。
HELP
	);
	return 1;
}
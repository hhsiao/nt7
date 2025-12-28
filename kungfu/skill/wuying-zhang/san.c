// san.c
// 天女散花 san
// 無影穿心掌[wuying-zhang] 的特攻

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int ski, am, can = 4;
	int ap,dp,left, damage;

	if( !target )
		target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『天女散花』只能對戰鬥中的對手使用。\n");

	if(!objectp(weapon = me->query_temp("weapon"))
	|| (weapon->query("skill_type") != "throwing") )
	{
		left = 1;
		if(!objectp(weapon = me->query_temp("secondary_weapon"))
		|| (weapon->query("skill_type") != "throwing") )
			return notify_fail("你手裡沒有暗器，無法使用『天女散花』。\n");
	}

	if(!am = weapon->query_amount())
		return notify_fail("你手裡沒有暗器，無法使用『天女散花』。\n");

	if((ski = me->query_skill("wuying-zhang", 1)) < 150)
		return notify_fail("你的『無影穿心掌』火候不夠，不會使用『天女散花』。\n");

	if(me->query("force") < 200)
		return notify_fail("你的真氣不夠，無法使用『天女散花』。\n");

	me->add("force", -200);

	if(ski >= 280)
		can = 6;
	else if(ski >= 220)
		can = 5;

	if(am < can)
		can = am;

	ap = COMBAT_D->skill_power(me,"throwing",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)/2 + COMBAT_D->skill_power(target,"perception",SKILL_USAGE_DEFENSE);

	message_vision(sprintf("\n$N%s手一揚，把手中%s用『天女散花』手法朝著$n打了過去。\n\n",
		left?"左":"右",
		weapon->name()), me, target);

	damage = weapon->query("weapon_prop/damage")/2;

	for(int i=0; i<can; i++)
	{
		if(random(ap + dp) >= dp)	// 打中
		{
			target->receive_damage("kee", damage+random(damage), me);
			COMBAT_D->report_status(target);
		}
	}

	if(can >= am)
	{
		weapon->unequip();
		tell_object(me, sprintf("\n你的%s打完了。\n\n", weapon->name()));
	}
	weapon->add_amount(-can);

	me->start_perform_busy(11);
	return 1;
}


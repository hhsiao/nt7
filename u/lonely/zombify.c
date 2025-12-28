#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int i;
	mapping buff;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「空魂異血」只能對戰鬥中的對手使用。\n");

	if (ANNIE_D->check_buff(target,"cursedflesh"))
		return notify_fail("對方已經受到類似技能的影響了。\n");

	buff =
	([
		"caster":me,
		"who":	target,
		"type": "cursedflesh",
		"att": "curse",
		"name": "破邪心經·空魂異血",
		"time": 30,
		"buff_msg":HIC"\n$n"HIC"面上浮現出青藍之色，噴出一團腥臭的煙氣。\n"HIB"$N"HIB"猝不及防，吸進一口毒霧，登時搖搖欲墜．．．\n\n"NOR,
	]);
	ANNIE_D->buffup(buff);
	me->perform_busy(2);
	return 1;
}

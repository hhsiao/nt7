// liu.c
// 流花掠影 liu
// 流花掠影劍法[liuhua-sword]的特攻
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	object weapon;

	if((skill = me->query_skill("liuhua-sword",1)) < 100)
		return notify_fail("你的流花掠影劍法不夠純熟，無法使用『流花掠影』。\n");

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("『流花掠影』只能對戰鬥中的對手使用。\n");

	if(me->query("force") < 400 )
		return notify_fail("你目前的內力不足，無法施展『流花掠影』。\n");

	if(!weapon = me->query_temp("weapon") || weapon->query("skill_type") != "sword"
	|| me->query_skill_mapped("sword") != "liuhua-sword")
		return notify_fail("你必須在使用劍時才能使出『流花掠影』。\n");

	me->add("force",-300);

	message_vision(HIR"$N手中亂抖，幻出一片青光，施展出唐門絕學『流花掠影』。\n\n"NOR,me);

	for(int i=0;i<4;i++)
	{
		COMBAT_D->do_attack(me,target,TYPE_QUICK);
	}

	if(random(target->query("force")) < me->query("force")/2)
	{
		target->apply_condition("weapon_bleeding", 5+random(3));
		me->start_busy(1);
	}

	// start_perform_busy() 為使用 perform 的間隔，單位為心跳數。
	// 每個 perform 必須由此設置，即：perform 是不能連續使用的。

	me->start_perform_busy(8);
	return 1;
}


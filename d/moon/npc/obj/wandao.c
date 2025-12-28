//ken 1999.12.17

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIC "圓月彎刀" NOR, ({ "wandao" }) );
	set_weight(7000);
        set("value", 20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("for_modao",3);
		set("long", "這是一把形狀很奇特的刀，刀身彷彿有點彎曲。\n");
		set("material", "steel");
		set("wield_msg", "$N的$n突然出鞘，你根本就沒有看見$N拔刀！\n");
		set("unwield_msg", "$N的$n已入鞘。\n");
	}
	init_blade(90);
	setup();
}
int query_autoload() { return 1; } 
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int dam ,pro;
        pro = (int)victim->query("force");
	dam = (int) me->query("force");
	if(dam > random(pro) )
	{
	victim->start_busy(1);
	return HIR "圓月彎刀迸發出霸道的刀氣，席捲$n的全身！$n氣為之窒，動彈不得！\n" NOR;
	}
}
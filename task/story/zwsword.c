

#include <weapon.h>
#include <ansi.h>

inherit TASK;

void create()
{
    set_name(HIC "真武劍" NOR, ({ "zwsword" }) );
	set_weight(7000);
        set("owner","張三豐");
		set("unit", "把");
        set("long", "這是武當鎮山之寶的真武寶劍。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        set("task",1);
        set("no_put_in",1);
	//init_sword(55);
	setup();
}

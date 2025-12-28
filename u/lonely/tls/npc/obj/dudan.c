// dan.c

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("毒丹", ({"du dan", "du", "dan"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顆");
		set("long", "這是一顆黑色的丹丸，好象有毒。\n");
		set("value", 100000);
		set("no_get", 1);
		set("no_drop", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你要吃什麼？\n");

	if ( me->query_skill_mapped("force") == "qiantian-yiyang" )
		return notify_fail("你現在所用內功不對，吃了反而會大損元氣。\n");
       
	if ( (int)me->query_condition("bonze_drug" ) > 0 )
		return notify_fail("你剛吃過靈藥，現在不能吃毒丹! \n");

	if ( me->query_skill_mapped("force") == "kurong-changong"){
		me->set("eff_qi", me->query("max_qi"));
		me->set("food", me->max_food_capacity());
		me->set("water", me->max_water_capacity());
		message_vision(HIG "$N吃下一顆毒丹，反而覺得精氣一振，似乎略有增漲。\n" NOR,me);
		destruct(this_object());
		return 1;
	}
	else {
		me->add("qi", -200);
		me->add("jing", -100);
                me->set("eff_qi", me->query("max_qi"));
		message_vision(HIR "$N吃下一顆毒丹，只覺得肝腸寸斷。\n" NOR, me);
		me->unconcious();
		destruct(this_object());
		return 1;
	}
	me->apply_condition("bonze_drug", 60);
	destruct(this_object());
	return 1;
}

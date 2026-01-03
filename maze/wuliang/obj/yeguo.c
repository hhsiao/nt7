// yeguo.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("野果", ({"ye guo", "guo"}));
	set_weight(80);
		set("unit", "個");
		set("value", 50);
		set("food_remaining", 3);
		set("food_supply", 20);
}

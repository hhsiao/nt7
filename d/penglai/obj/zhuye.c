#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL + GRN "竹葉" NOR, ({ "penglai zhuye" }) );
	set_weight(100);
	set("unit", "片");
		set("value", 1);
		set("long", YEL + GRN "這是一片竹葉，還帶著仙氣。\n" NOR);

	setup();
}

int query_autoload()
{
	return 1;
}

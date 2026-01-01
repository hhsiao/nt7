#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC "青梅" NOR, ({ "penglai qingmei" }) );
	set_weight(100);
	set("unit", "顆");
		set("value", 1);
		set("long", HIC "從長生梅林中採集而來的青梅。\n" NOR);

	setup();
}

int query_autoload()
{
	return 1;
}

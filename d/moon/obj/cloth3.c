// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("青絲長衫", ({ "silk cloth"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "這是風雲城時下最時髦的衣服。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	setup();
}
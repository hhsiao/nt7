//nianzhu.c

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( "念珠", ({ "nian zhu", "nianzhu" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
                set("long", "這是一副念珠，黑沉沉的不知是用什麼製成的，看起來非常圓潤，想必經常被撫摸滾動。\n");
		set("value", 0);
		set("material", "hand");
		set("armor_prop/armor", 5);
			}
	setup();
}

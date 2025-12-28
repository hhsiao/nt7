
 
// poison_dust.c

#include <ansi.h>
inherit TASK;
void create()
{
    set_name(HIY"迷春藥"NOR, ({ "poison_dust", "dust" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
            "這是韋春芳的春藥，你可以把它倒在酒水之中使用。\n" );
		set("unit", "包");
		set("base_value", 700);
        set("owner","韋春芳");
        set("task",1);
		set("base_unit", "份");
		set("base_weight", 30);
        set("no_put_in",1); 
	}
	setup();
}

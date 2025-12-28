 
// 七寶天嵐舞

inherit TASK;
#include <ansi.h>
void create()
{
	set_name(YEL"七寶天嵐舞"NOR, ({"stormdance_book"}));
	set_weight(600);
	set("task",1);
        set("owner","狂風");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"一本關於七寶天嵐舞的入門舞姿的書籍。\n"
			"\t\t\t\------狂風注\n");
		set("value", 1000);
		set("material", "paper");
	}
	setup();
}

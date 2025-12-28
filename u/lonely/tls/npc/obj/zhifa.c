// zhifa.c 指法訣要

inherit ITEM;

void create()
{
	set_name("指法訣要", ({ "zhifa jueyao", "jueyao", "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "這是一本講解指法入門練功訣要的線裝書。\n");
		set("value", 30);
		set("material", "paper");
		set("skill", ([
			"name":	"finger",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost":	15,	// jing cost every time study this
			"difficulty":	25,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}

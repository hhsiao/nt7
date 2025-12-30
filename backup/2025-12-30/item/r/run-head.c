// ITEM Made by player(糙漢:run) /data/item/r/run-head.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Feb  1 15:13:06 2019
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("頭盔[2;37;0m", ({ "head" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "頂");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一頂頭盔。
頭盔很霸道[2;37;0m
");
	set("makeinfo", "[1;31m
糙漢(run)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 750);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 6);
	set("wear_msg", "頭盔一出，天下寂靜[2;37;0m\n");
	set("remove_msg", "頭盔一收很安靜[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/avoid_freeze", 0);
	set("armor_prop/avoid_weak", 2.500000);
	set("armor_prop/research_effect", 6);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

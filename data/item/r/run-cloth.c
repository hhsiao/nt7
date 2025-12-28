// ITEM Made by player(糙漢:run) /data/item/r/run-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Feb  1 13:26:55 2019
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("戰衣[2;37;0m", ({ "cloth" }));
	set_weight(20000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一件戰衣。
這個衣服很好看[2;37;0m
");
	set("makeinfo", "[1;31m
糙漢(run)[1;31m 出品
[2;37;0m");
	set("value", 35500000);
	set("point", 1770);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 6);
	set("wear_msg", "衣服穿起來，漂亮極了[2;37;0m\n");
	set("remove_msg", "衣服收起來，光禿禿的[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/avoid_freeze", 0);
	set("armor_prop/counter_damage", 2.500000);
	set("armor_prop/practice_effect", 3);
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

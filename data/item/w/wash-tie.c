// ITEM Made by player(湖中:wash) /data/item/w/wash-tie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 17 19:33:23 2019
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("鐵手[2;37;0m", ({ "tie" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "雙");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一雙護手。
");
	set("makeinfo", "[1;31m
湖中(wash)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 476);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 2);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

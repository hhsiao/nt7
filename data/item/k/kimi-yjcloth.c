// ITEM Made by player(雪山飛龍:kimi) /data/item/k/kimi-yjcloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Feb  9 11:59:13 2019
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m知章[1;35m騎馬[1;37m似乘船[2;37;0m", ({ "yjcloth" }));
	set_weight(20000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一件戰衣。
知章騎馬似乘船，眼花落井水底眠[2;37;0m
");
	set("makeinfo", "[1;31m
雪山飛龍(kimi)[1;31m 出品
[2;37;0m");
	set("value", 34880000);
	set("point", 1739);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 5);
	set("wear_msg", "眼花落井水底眠[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/qi_recover", 40);
	set("armor_prop/reduce_poison", 1.500000);
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

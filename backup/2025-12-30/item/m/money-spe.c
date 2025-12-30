// ITEM Made by player(財迷:money) /data/item/m/money-spe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan 16 11:37:51 2019
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[43;1m雙龍戲珠冠[2;37;0m", ({ "spe" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "頂");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一頂頭盔。
");
	set("makeinfo", "[1;31m
財迷(money)[1;31m 出品
[2;37;0m");
	set("value", 35520000);
	set("point", 885);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 6);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/reduce_busy", 2.500000);
	set("armor_prop/avoid_weak", 2.500000);
	set("armor_prop/research_effect", 6);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

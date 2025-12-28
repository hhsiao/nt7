// ITEM Made by player(冒險遊戲:avg) /data/item/a/avg-yjd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan  9 10:39:17 2019
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m研究頭[2;37;0m", ({ "yjd" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "頂");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一頂頭盔。
");
	set("makeinfo", "[1;31m
冒險遊戲(avg)[1;31m 出品
[2;37;0m");
	set("value", 35880000);
	set("point", 894);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 2);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

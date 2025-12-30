// ITEM Made by player(風四郎:alxpang) /data/item/a/alxpang-ironc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jan 26 10:17:31 2019
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("青鋼甲[2;37;0m", ({ "ironc" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "張");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一張護甲。
");
	set("makeinfo", "[1;31m
風四郎(alxpang)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 1200);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 2);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

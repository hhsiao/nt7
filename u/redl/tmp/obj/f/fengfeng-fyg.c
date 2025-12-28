// ITEM Made by player(風風:fengfeng) /data/item/f/fengfeng-fyg.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct  4 11:22:52 2014
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[41;1m[1;33m福源護腕[2;37;0m", ({ "fyg" }));
	set_weight(500);
	set("item_make", 1);
	set("unit", "對");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一對護腕。
");
	set("makeinfo", "[1;31m
風風(fengfeng)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 375);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/kar", 9);

	setup();
}

string long() { return short() + query("makeinfo") + query("long") + item_long(); }

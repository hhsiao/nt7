// ITEM Made by player(石頭:stone) /data/item/s/stone-stp.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 22 13:12:34 2019
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_ITEMMAKE;

void create()
{
	set_name("石頭披風[2;37;0m", ({ "stp" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一件披風。
");
	set("makeinfo", "[1;31m
石頭(stone)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 344);
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

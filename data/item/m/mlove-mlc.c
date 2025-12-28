// ITEM Made by player(塗鴉人生:mlove) /data/item/m/mlove-mlc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jan  7 11:05:55 2019
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m研[1;33m究[1;31m套[2;37;0m", ({ "mlc" }));
	set_weight(6000);
	set("item_make", 1);
	set("unit", "雙");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一雙靴子。
");
	set("makeinfo", "[1;31m
塗鴉人生(mlove)[1;31m 出品
[2;37;0m");
	set("value", 34280000);
	set("point", 683);
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

// ITEM Made by player(動作遊戲:act) /data/item/a/act-yjf.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 15 18:15:33 2019
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m研究腕[2;37;0m", ({ "yjf" }));
	set_weight(5000);
	set("item_make", 1);
	set("unit", "對");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一對護腕。
");
	set("makeinfo", "[1;31m
動作遊戲(act)[1;31m 出品
[2;37;0m");
	set("value", 34640000);
	set("point", 431);
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

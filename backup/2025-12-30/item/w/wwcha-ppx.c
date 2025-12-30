// ITEM Made by player(大波龍:wwcha) /data/item/w/wwcha-ppx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jan 19 14:54:11 2019
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m蔭死你[2;37;0m", ({ "ppx" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "張");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一張護甲。
");
	set("makeinfo", "[1;31m
大波龍(wwcha)[1;31m 出品
[2;37;0m");
	set("value", 35180000);
	set("point", 1403);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/jing_recover", 40);
	set("armor_prop/practice_effect", 3);
	set("armor_prop/reduce_busy", 2.500000);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

// ITEM Made by player(滅下:sky) /data/item/s/sky-ddd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 18 10:29:43 2019
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[45;1m混沌鍾[2;37;0m", ({ "ddd", "ddd" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "張");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一張護甲。
");
	set("makeinfo", "[1;31m
滅下(sky)[1;31m 出品
[2;37;0m");
	set("value", 35420000);
	set("point", 1412);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 6);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/avoid_forget", 2.500000);
	set("armor_prop/research_effect", 9);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

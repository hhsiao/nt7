// ITEM Made by player(魔虎:uuu) /data/item/u/uuu-respf.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun  4 22:21:47 2019
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m研絕腰帶[2;37;0m", ({ "respf" }));
	set_weight(800);
	set("item_make", 1);
	set("unit", "條");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一條腰帶。
");
	set("makeinfo", "[1;31m
魔虎(uuu)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 600);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 5);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 6);
	set("armor_prop/str", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

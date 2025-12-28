// ITEM Made by player(上單:top) /data/item/t/top-pro.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jan 13 15:21:00 2019
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m護腰[2;37;0m", ({ "pro" }));
	set_weight(800);
	set("item_make", 1);
	set("unit", "條");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一條腰帶。
");
	set("makeinfo", "[1;31m
上單(top)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 120);
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

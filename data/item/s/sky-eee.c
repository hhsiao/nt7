// ITEM Made by player(滅下:sky) /data/item/s/sky-eee.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 18 11:04:57 2019
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[45;1m乾坤鼎[2;37;0m", ({ "eee", "eee" }));
	set_weight(8000);
	set("item_make", 1);
	set("unit", "條");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一條腰帶。
");
	set("makeinfo", "[1;31m
滅下(sky)[1;31m 出品
[2;37;0m");
	set("value", 36100000);
	set("point", 720);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 6);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/full_self", 2.500000);
	set("armor_prop/research_effect", 9);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

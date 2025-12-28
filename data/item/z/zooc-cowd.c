// ITEM Made by player(靈牛:zooc) /data/item/z/zooc-cowd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 21 00:21:56 2019
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m莽牛皮護甲[2;37;0m", ({ "cowd" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "張");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一張護甲。
");
	set("makeinfo", "[1;31m
靈牛(zooc)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 1200);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 4);
	set("wear_msg", "[33m$N[33m裝備[33m$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脫下了[33m$n[33m。[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", 20);
	set("armor_prop/neili_recover", 70);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

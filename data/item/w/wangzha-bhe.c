// ITEM Made by player(王詐:wangzha) /data/item/w/wangzha-bhe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jan 27 21:20:08 2019
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m百花盔[2;37;0m", ({ "bhe" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "頂");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一頂頭盔。
");
	set("makeinfo", "[1;31m
王詐(wangzha)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 288);
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

// ITEM Made by player(東邪西毒:kimic) /data/item/k/kimic-xblade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar  8 09:41:14 2019
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m好好[1;37m學習[2;37;0m", ({ "xblade" }));
	set_weight(45000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "這是由[36m玄鐵[2;37;0m煉製而成的一把刀。
[1;32m好好學習，天天向上[2;37;0m
");
	set("makeinfo", "[1;31m
東邪西毒(kimic)[1;31m 出品
[2;37;0m");
	set("value", 1500000);
	set("point", 70);
	set("max_consistence", 100);
	set("material", "steel");
	set("material_file", "/d/item/obj/xuantie");
	set("quality_level", 2);
	set("wield_msg", "[1;33m為[1;36m人民[1;37m[5m服務[2;37;0m\n");
	set("unwield_msg", "[1;33m為[1;36m人民[1;37m[5m服務[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

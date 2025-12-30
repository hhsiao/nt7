// ITEM Made by player(勞動者:jobb) /data/item/j/jobb-wdj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Feb 15 23:59:01 2019
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("無敵劍[2;37;0m", ({ "wdj" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一柄劍。
");
	set("makeinfo", "[1;31m
勞動者(jobb)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 882);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 2);
	set("wield_msg", "[1;36m$N[1;36m一聲清嘯，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N隨手一抹，收起了$n。\n");
	if( !check_clone() ) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

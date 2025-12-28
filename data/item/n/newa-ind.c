// ITEM Made by player(一二三:newa) /data/item/n/newa-ind.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Feb 13 19:54:15 2019
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("太極[2;37;0m", ({ "ind" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "這是由[1;35m寒星隕鐵[2;37;0m煉製而成的一柄劍。
");
	set("makeinfo", "[1;31m
一二三(newa)[1;31m 出品
[2;37;0m");
	set("value", 4100000);
	set("point", 548);
	set("max_consistence", 100);
	set("material", "hanxing yuntie");
	set("material_file", "/clone/goods/hanxing-yuntie");
	set("quality_level", 2);
	set("wield_msg", "[1;36m$N[1;36m一聲清嘯，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N隨手一抹，收起了$n。\n");
	if( !check_clone() ) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

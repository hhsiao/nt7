// ITEM Made by player(渡玩:alp) /data/item/a/alp-zzj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Feb 14 08:27:00 2019
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("中正劍[2;37;0m", ({ "zzj" }));
	set_weight(45000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "這是由[36m玄鐵[2;37;0m煉製而成的一柄劍。
");
	set("makeinfo", "[1;31m
渡玩(alp)[1;31m 出品
[2;37;0m");
	set("value", 1500000);
	set("point", 221);
	set("max_consistence", 100);
	set("material", "steel");
	set("material_file", "/d/item/obj/xuantie");
	set("quality_level", 2);
	set("wield_msg", "[1;36m$N[1;36m一聲清嘯，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N隨手一抹，收起了$n。\n");
	if( !check_clone() ) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

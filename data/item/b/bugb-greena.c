// ITEM Made by player(渡綠:bugb) /data/item/b/bugb-greena.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 11 19:22:50 2019
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m隱綠劍[2;37;0m", ({ "greena" }));
	set_weight(1500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一柄劍。
");
	set("makeinfo", "[1;31m
渡綠(bugb)[1;31m 出品
[2;37;0m");
	set("value", 6100000);
	set("point", 1500);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname");
	set("quality_level", 5);
	set("wield_msg", "[1;36m$N[1;36m一聲清嘯，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N隨手一抹，收起了$n。\n");
	if( !check_clone() ) return;
	restore();
	init_sword(apply_damage());
	set("weapon_prop/int", 3);
	set("weapon_prop/leech_qi", 2.000000);
	set("weapon_prop/add_freeze", 2.500000);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

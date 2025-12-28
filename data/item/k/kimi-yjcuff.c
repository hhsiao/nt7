// ITEM Made by player(雪山飛龍:kimi) /data/item/k/kimi-yjcuff.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Feb 11 22:15:35 2019
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m飲中[1;35m八仙[1;37m歌[2;37;0m", ({ "yjcuff" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "雙");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一雙鐵掌。
[1;32m飲如長鯨吸百川，揮毫落紙如雲煙[2;37;0m
");
	set("makeinfo", "[1;31m
雪山飛龍(kimi)[1;31m 出品
[2;37;0m");
	set("value", 35080000);
	set("point", 1749);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m飲如[1;36m長鯨[1;37m[5m吸百川[2;37;0m\n");
	set("remove_msg", "[1;32m揮毫[1;37m落紙[1;36m[5m如雲煙[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

// ITEM Made by player(雪山飛龍:kimi) /data/item/k/kimi-yjhead.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Feb  9 21:46:53 2019
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m汝陽[1;35m三鬥[1;37m始朝天[2;37;0m", ({ "yjhead" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "頂");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一頂頭盔。
汝陽三鬥始朝天，道逢鞠車口流涎，恨不移封向酒泉[2;37;0m
");
	set("makeinfo", "[1;31m
雪山飛龍(kimi)[1;31m 出品
[2;37;0m");
	set("value", 35540000);
	set("point", 886);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "道逢鞠車口流涎[2;37;0m\n");
	set("remove_msg", "恨不移封向酒泉[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

// ITEM Made by player(雪山飛龍:kimi) /data/item/k/kimi-yjboots.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 10 00:32:43 2019
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m蘇晉[1;35m長齋[1;37m繡佛前[2;37;0m", ({ "yjboots" }));
	set_weight(6000);
	set("item_make", 1);
	set("unit", "雙");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一雙靴子。
[1;32m蘇晉長齋繡佛前，醉中往往愛逃禪[2;37;0m
");
	set("makeinfo", "[1;31m
雪山飛龍(kimi)[1;31m 出品
[2;37;0m");
	set("value", 35360000);
	set("point", 705);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m蘇晉[1;36m長齋[1;37m[5m繡佛前[2;37;0m\n");
	set("remove_msg", "[1;32m醉中[1;37m往往[1;36m[5m愛逃禪[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

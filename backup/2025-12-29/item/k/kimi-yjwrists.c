// ITEM Made by player(雪山飛龍:kimi) /data/item/k/kimi-yjwrists.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 10 00:13:35 2019
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m左相[1;35m日興[1;37m費萬錢[2;37;0m", ({ "yjwrists" }));
	set_weight(5000);
	set("item_make", 1);
	set("unit", "對");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一對護腕。
[1;32m左相日興費萬錢，飲如長鯨吸百川，銜杯樂聖稱世賢[2;37;0m
");
	set("makeinfo", "[1;31m
雪山飛龍(kimi)[1;31m 出品
[2;37;0m");
	set("value", 35420000);
	set("point", 441);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 4);
	set("wear_msg", "[1;33m飲如[1;36m長鯨[1;37m[5m吸百川[2;37;0m\n");
	set("remove_msg", "[1;32m銜杯[1;37m樂聖[1;36m[5m稱世賢[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/derive_times", 10);
	set("armor_prop/research_effect", 2);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

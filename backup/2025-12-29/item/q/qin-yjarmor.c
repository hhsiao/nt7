// ITEM Made by player(秦雲:qin) /data/item/q/qin-yjarmor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 26 13:35:19 2019
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m氣吞[1;35m萬里[1;37m如虎[2;37;0m", ({ "yjarmor" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "張");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一張護甲。
[1;32m金戈鐵馬，氣吞萬里如虎。[2;37;0m
");
	set("makeinfo", "[1;31m
秦雲(qin)[1;31m 出品
[2;37;0m");
	set("value", 34840000);
	set("point", 1389);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m金[1;36m戈[1;37m[5m鐵馬[2;37;0m\n");
	set("remove_msg", "[1;32m氣吞[1;37m萬里[1;36m[5m如虎[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

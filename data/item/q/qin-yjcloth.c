// ITEM Made by player(秦雲:qin) /data/item/q/qin-yjcloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 26 13:25:13 2019
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m人生[1;35m如[1;37m夢[2;37;0m", ({ "yjcloth" }));
	set_weight(20000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一件戰衣。
[1;32m人生如夢，一尊還酹江月。[2;37;0m
");
	set("makeinfo", "[1;31m
秦雲(qin)[1;31m 出品
[2;37;0m");
	set("value", 35600000);
	set("point", 1775);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m人生[1;36m如[1;37m[5m夢[2;37;0m\n");
	set("remove_msg", "[1;32m一尊[1;37m還酹[1;36m[5m江月[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

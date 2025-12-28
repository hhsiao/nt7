// ITEM Made by player(秦雲:qin) /data/item/q/qin-yjboots.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 26 13:44:46 2019
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m踏破[1;35m賀蘭山[1;37m缺[2;37;0m", ({ "yjboots" }));
	set_weight(6000);
	set("item_make", 1);
	set("unit", "雙");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一雙靴子。
[1;32m駕長車，踏破賀蘭山缺。[2;37;0m
");
	set("makeinfo", "[1;31m
秦雲(qin)[1;31m 出品
[2;37;0m");
	set("value", 34920000);
	set("point", 696);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m三十[1;36m功名[1;37m[5m塵與土[2;37;0m\n");
	set("remove_msg", "[1;32m八千[1;37m里路[1;36m[5m雲和月[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

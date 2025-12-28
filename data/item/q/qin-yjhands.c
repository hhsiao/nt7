// ITEM Made by player(秦雲:qin) /data/item/q/qin-yjhands.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun 27 14:15:19 2019
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m驚[1;35m濤[1;37m拍岸[2;37;0m", ({ "yjhands" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "雙");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一雙鐵掌。
[1;32m亂石穿空，驚濤拍岸，捲起千堆雪。[2;37;0m
");
	set("makeinfo", "[1;31m
秦雲(qin)[1;31m 出品
[2;37;0m");
	set("value", 36040000);
	set("point", 1797);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m亂石穿空[1;36m驚濤拍岸[1;37m[5m捲起千堆雪[2;37;0m\n");
	set("remove_msg", "[1;32m羽扇綸巾[1;37m談笑間[1;36m[5m強虜灰飛煙滅[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

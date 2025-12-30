// ITEM Made by player(秦雲:qin) /data/item/q/qin-ysurcoat.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun 27 14:17:57 2019
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m青山[1;35m多[1;37m嫵媚[2;37;0m", ({ "ysurcoat" }));
	set_weight(10000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一件披風。
[1;32m我見青山多嫵媚，料青山見我應如是。[2;37;0m
");
	set("makeinfo", "[1;31m
秦雲(qin)[1;31m 出品
[2;37;0m");
	set("value", 34560000);
	set("point", 861);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m我見[1;36m青山[1;37m[5m多嫵媚[2;37;0m\n");
	set("remove_msg", "[1;32m料青山[1;37m見我[1;36m[5m應如是[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 2);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

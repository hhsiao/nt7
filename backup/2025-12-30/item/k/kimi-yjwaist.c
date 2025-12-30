// ITEM Made by player(雪山飛龍:kimi) /data/item/k/kimi-yjwaist.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb 10 00:26:30 2019
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m宗之[1;35m瀟灑[1;37m美少年[2;37;0m", ({ "yjwaist" }));
	set_weight(8000);
	set("item_make", 1);
	set("unit", "條");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一條腰帶。
[1;32m宗之瀟灑美少年，舉觴白眼望青天，皎如玉樹臨風前。[2;37;0m
");
	set("makeinfo", "[1;31m
雪山飛龍(kimi)[1;31m 出品
[2;37;0m");
	set("value", 35460000);
	set("point", 707);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wear_msg", "[1;33m舉觴[1;36m白眼[1;37m[5m望青天[2;37;0m\n");
	set("remove_msg", "[1;32m皎如[1;37m玉樹[1;36m[5m臨風前[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

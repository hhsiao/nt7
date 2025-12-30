// ITEM Made by player(秦雲:qin) /data/item/q/qin-yjblade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 26 13:08:21 2019
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m寒[1;35m蟬[1;37m悽切[2;37;0m", ({ "yjblade" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "這是由[1;35m無名之物[2;37;0m煉製而成的一把刀。
[1;32m寒蟬悽切，對長亭晚，驟雨初歇。[2;37;0m
");
	set("makeinfo", "[1;31m
秦雲(qin)[1;31m 出品
[2;37;0m");
	set("value", 34880000);
	set("point", 1739);
	set("max_consistence", 100);
	set("material", "no name");
	set("material_file", "/clone/goods/noname2");
	set("quality_level", 3);
	set("wield_msg", "[1;33m念去去[1;36m千里煙波[1;37m[5m暮靄沉沉楚天闊[2;37;0m\n");
	set("unwield_msg", "[1;32m多情自古傷離別[1;37m更那堪[1;36m[5m冷落清秋節[2;37;0m\n");
	if( !check_clone() ) return;
	restore();
	init_blade(apply_damage());
	set("weapon_prop/research_effect", 3);

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }

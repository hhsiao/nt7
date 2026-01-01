#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("鋼刀", ({ "gang dao", "gang", "dao", "blade" }));
        set_weight(7000);
        set("unit", "柄");
                set("long", "這是一柄亮晃晃的鋼刀，普通官兵的常備武器。\n");
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回刀鞘。\n");
        init_blade(5);
        set("no_pk", 1);
	setup();
}

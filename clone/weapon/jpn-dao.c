// jpn-dao

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("東洋刀", ({ "blade", "dao" }));
        set_weight(5000);
        set("unit", "柄");
                set("long", "這是一柄細長略彎的東洋長刀，形狀怪異，似劍似刀。\n");
                set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回刀鞘。\n");
        init_blade(50);
        setup();
}

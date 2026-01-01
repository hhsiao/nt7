#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("菜刀", ({ "cai dao", "blade" }));
        set_weight(7000);
        set("unit", "柄");
                set("long", "這是一柄亮晃晃的菜刀。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回褲腰。\n");
        init_blade(5);
        setup();
}

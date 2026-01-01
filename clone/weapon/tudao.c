// tudao.c

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("屠刀", ({ "knife" }));
        set_weight(7000);
        set("unit", "柄");
                set("long", "這是一血淋淋的屠刀。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一聲抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插回刀鞘。\n");
        init_blade(30);
        setup();
}

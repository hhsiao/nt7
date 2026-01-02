#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create() {
    set_name("長吟劍", ({ "long sword" , "sword" }) );
    set_weight(3000);
    set("value", 10000);
    set("unit", "把");
    set("long",
        "這是一把長吟劍。\n");
    set("value", 10000);
    set("for_bandit", 1);
    set("material", "steel");
    set("wield_msg", "$N從劍鞘中抽出一柄劍光閃閃的$n。\n");
    set("unwield_msg", "$N將$n插回劍鞘之中。\n");

    init_sword(50);
    setup();

}

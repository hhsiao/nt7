// jindao.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create() {
    set_name("金刀", ({"jin dao", "dao"}));
    set_weight(8000);
    set("unit", "把");
    set("long", "一把金光閃閃的圓頭長刀，刀把上鑲嵌有白玉。\n");
    set("value", 2500);
    set("material", "gold");
    set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中，金光閃閃！\n");
    set("unwield_msg", "$N將手中的$n插入金色刀鞘。\n");
    set("weapon_prop/courage", 15);
    init_blade(50);
    setup();
}

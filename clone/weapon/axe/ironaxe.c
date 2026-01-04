// ironaxe.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit AXE;

void create() {
    set_name("鐵斧", ({ "tiefu", "axe", "fu", "tie fu" }) );
    set_weight(8000);
    set("unit", "把");
    set("long", "這是一把劈柴用的鐵斧，砍起東西來非常順手。\n");
    set("value", 1000);
    set("wield_msg", "$N拿出一把砍柴的$n，握在手中當作武器。\n");
    set("unwield_msg", "$N放下手中的$n。\n");
    init_axe(20);
    setup();
}

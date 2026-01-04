// ring.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit FINGER;

void create() {
    set_name("戒指", ({ "ring", "jie zhi" }) );
    set_weight(800);
    set("unit", "個");
    set("material", "gold");
    set("value", 100);
    set("armor_prop/armor", 2);
    setup();
}

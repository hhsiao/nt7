// armor.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>

inherit ARMOR;

void create() {
    set_name("鎧甲", ({"armor"}));
    set_weight(3000);
    set("material", "iron");
    set("unit", "副");
    set("armor_prop/armor", 5);
    setup();
}

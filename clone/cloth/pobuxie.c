//pobuxie.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create() {
    set_name("破布鞋", ({"po buxie", "buxie", "shoes"}));
    set_weight(800);
    set("unit", "雙");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

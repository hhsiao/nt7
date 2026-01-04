// head.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit HEAD;

void create() {
    set_name("頭盔", ({"head"}));
    set_weight(1000);
    set("material", "iron");
    set("unit", "個");
    set("armor_prop/armor", 1);
    setup();
}

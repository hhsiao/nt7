// finger.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit FINGER;

void create() {
    set_name("指套", ({"finger"}));
    set_weight(1000);
    set("material", "iron");
    set("unit", "套");
    set("armor_prop/armor", 1);
    setup();
}

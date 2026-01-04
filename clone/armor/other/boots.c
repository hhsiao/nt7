// boots.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create() {
    set_name("靴子", ({"boots"}));
    set_weight(1000);
    set("material", "leather");
    set("unit", "雙");
    set("armor_prop/armor", 1);
    setup();
}

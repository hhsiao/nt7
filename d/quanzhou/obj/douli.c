// douli.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit HEAD;

void create() {
    set_name("斗笠", ({ "dou li", "douli" }) );
    set_weight(800);
    set("unit", "頂");
    set("material", "cloth");
    set("value", 150);
    set("armor_prop/armor", 2);
    setup();
}

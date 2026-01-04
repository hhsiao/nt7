// hat.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit HEAD;

void create() {
    set_name("氈帽", ({ "zhan mao", "hat" }) );
    set_weight(800);
    set("unit", "頂");
    set("material", "cloth");
    set("value", 100);
    set("armor_prop/armor", 2);
    setup();
}

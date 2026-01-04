// sengyi.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create() {
    set_name("僧衣", ({"seng yi", "cloth"}));
    set_weight(1000);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 2);
    setup();
}

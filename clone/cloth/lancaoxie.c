// lancaoxie.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create() {
    set_name("爛草鞋", ({"lan caoxie", "caoxie", "shoes"}));
    set_weight(800);
    set("unit", "雙");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

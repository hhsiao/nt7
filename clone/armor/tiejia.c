// tiejia.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit ARMOR;

void create() {
    set_name("鐵甲", ({"iron armor", "tiejia", "jia", "armor"}));
    set_weight(40000);
    set("unit", "件");
    set("long", "一件沉甸甸的鐵甲。\n");
    set("value", 3000);
    set("material", "steel");
    set("armor_prop/armor", 40);
    set("armor_prop/dodge", -10);
    setup();
}

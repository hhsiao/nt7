// tongjia.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit ARMOR;

void create() {
    set_name("熟銅甲", ({"bronze armor", "tongjia", "jia", "armor"}));
    set_weight(50000);
    set("unit", "件");
    set("long", "一件金燦燦的熟銅甲。\n");
    set("value", 5000);
    set("material", "steel");
    set("armor_prop/armor", 45);
    set("armor_prop/dodge", -15);
    setup();
}

// tengjia.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit ARMOR;

void create() {
    set_name("藤甲", ({"teng jia", "tengjia", "jia", "armor"}));
    set_weight(8000);
    set("unit", "件");
    set("long", "一件輕便藤甲。\n");
    set("value", 1500);
    set("material", "wood");
    set("armor_prop/armor", 25);
    setup();
}

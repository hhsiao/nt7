// Last Modified by Lonely on May. 25 2001
// yinjia.c

#include <armor.h>
inherit ARMOR;

void create() {
    set_name("亮銀甲", ({"silver armor", "jia", "armor"}));
    set_weight(30000);
    set("unit", "件");
    set("long", "一件銀光燦燦的盔甲．\n");
    set("value", 8000);
    set("material", "iron");
    set("armor_prop/armor", 45);
    set("armor_prop/dodge", -10);
    setup();
}

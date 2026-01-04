// wizjia.c 御用甲
//

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("御用甲", ({ "wizard armor", "armor", "jia" }) );
    set_weight(20000);
    set("unit", "件");
    set("material", "steel");
    set("value", 2000);
    set("armor_prop/armor", 1000);
    setup();
}

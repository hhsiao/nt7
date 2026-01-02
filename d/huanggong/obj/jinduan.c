// jinduan.c
//

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("錦緞", ({"jin duan", "jin", "duan"}));
    set_weight(3000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 10);
    set("value", 10000);
    setup();
}

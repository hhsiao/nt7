// jinduan.c

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("錦緞", ({ "jin duan", "jinduan", "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "絲");
    set("value", 5000);
    set("armor_prop/armor", 3);
    setup();
}

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("安南軍軍服", ({ "junfu", "cloth" }) );
    set_weight(6000);
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
    set("armor_prop/armor", 80);
    setup();
}

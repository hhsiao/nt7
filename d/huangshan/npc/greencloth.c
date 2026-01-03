#include <armor.h>

inherit CLOTH;

void create() {
    set_name("粗布白袍", ({ "cloth" }) );
    set_weight(1000);
        set("unit", "件");
        set("material", "cloth");
        set("armor_prop/armor", 15);
    setup();
}

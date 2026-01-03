// hupi.c


#include <armor.h>

inherit CLOTH;

void create() {
    set_name("虎皮", ({ "hu pi", "pi" }) );
    set_weight(2000);
    set("unit", "塊");
    set("material", "fur");
    set("value", 2000);
    set("armor_prop/armor", 10);
    setup();
}

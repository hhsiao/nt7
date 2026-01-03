// haibaopi.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("海豹皮", ({ "haibao pi", "pi" }) );
    set_weight(5000);
        set("unit", "塊");
        set("material", "fur");
        set("value", 300);
        set("armor_prop/armor", 10);
    setup();
}

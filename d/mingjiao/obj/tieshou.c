// tieshou.c

#include <armor.h>

inherit HANDS;

void create() {
    set_name("鐵手掌", ({ "iron hand", "hand" }) );
    set_weight(2000);
    set("material", "steel");
    set("unit", "塊");
    set("value", 5);
    set("armor_prop/armor", 1 );
    setup();
}

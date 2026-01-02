// changpao.c
//

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("葛布長袍", ({ "gebu changpao", "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 3);
    setup();
}

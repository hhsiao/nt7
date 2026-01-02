// shoe.c

#include <armor.h>

inherit BOOTS;

void create() {
    set_name("繡花小鞋", ({ "flower shoes", "shoes" }) );
    set_weight(900);
    set("material", "cloth");
    set("unit", "雙");
    set("value", 300);
    set("armor_prop/armor", 1 );
    set("female_only", 1);
    setup();
}

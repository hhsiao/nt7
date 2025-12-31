// yaodai.c

#include <armor.h>

inherit WAIST;

void create() {
    set_name("腰帶", ({ "waist band", "waist", "band" }) );
    set_weight(500);
    set("unit", "條");
    set("value", 1000);
    set("material", "leather");
    set("armor_prop/armor", 3);
    set("female_only", 1);
    setup();
}

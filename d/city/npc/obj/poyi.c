// poyi.c

#include <armor.h>
inherit CLOTH;

void create() {
    set_name("舊布衣", ({ "cloth" }) );
    set_weight(2000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 0);
    setup();
}

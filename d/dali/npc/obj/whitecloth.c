// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("白衣", ({ "bai yi", "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "cloth");
    set("value", 100);
    set("armor_prop/armor", 1);
    setup();
}

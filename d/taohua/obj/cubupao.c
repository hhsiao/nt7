#include <armor.h>
inherit CLOTH;

void create() {
    set_name("粗布袍", ({ "cu bupao", "bupao", "pao"}));
    set_weight(1000);
    set("unit", "件");
    set("armor_type", "cloth");
    set("value", 100);
    set("armor_prop/dodge", 1);
    set("armor_prop/armor", 1);
    setup();
}

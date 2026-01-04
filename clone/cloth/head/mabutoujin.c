// mabutoujin.c

#include <armor.h>
inherit HEAD;
void create() {
    set_name("麻布頭巾", ({ "mabu toujin", "head" }) );
    set_weight(100);
    set("unit", "塊");
    set("value", 50);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

// wanzijin.c

#include <armor.h>
inherit HEAD;
void create() {
    set_name("萬字巾", ({ "wanzi jin", "head" }) );
    set_weight(100);
    set("unit", "塊");
    set("value", 300);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

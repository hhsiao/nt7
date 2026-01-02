//yinjie.c

#include <armor.h>

inherit HANDS;

void create() {
    set_name("銀戒指", ({ "yin jie", "yinjie", "ring" }));
    set("weight", 400);
    set("unit", "個");
    set("value", 1000);
    set("material", "silver");
    set("armor_prop/armor", 1);
    set("armor_prop/per", 1);

    setup();
}

//zuanjie.c

#include <armor.h>

inherit HANDS;

void create() {
    set_name("鑽石戒指", ({ "zuan jie", "zuanjie", "ring" }));
    set("weight", 400);
    set("unit", "個");
    set("value", 12000);
    set("material", "diamond");
    set("armor_prop/armor", 1);
    set("armor_prop/per", 1);

    setup();
}

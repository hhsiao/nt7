// necklace.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit NECK;

void create() {
    set_name("項鍊", ({ "xiang lian", "necklace" }) );
    set_weight(800);
    set("unit", "串");
    set("material", "pearl");
    set("value", 100);
    set("armor_prop/armor", 2);
    setup();
}

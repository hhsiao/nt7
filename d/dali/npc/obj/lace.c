// lace.c

#include <armor.h>

inherit NECK;

void create() {
    set_name("貝殼項鍊", ({ "shell lace", "lace" }));
    set_weight(500);
    set("unit", "串");
    set("value", 2500);
    set("armor_prop/armor", 5);
    setup();
}

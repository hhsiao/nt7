//baojie.c

#include <armor.h>

inherit HANDS;

void create()
{
        set_name("寶石戒指", ({ "bao jie", "baojie", "ring" }));
        set("weight", 400);
        set("unit", "個");
                set("value", 10000);
                set("material", "gold");
                set("armor_prop/armor", 1);
                set("armor_prop/per", 1);
        setup();
}

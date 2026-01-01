// goldring.c 金戒指

#include <armor.h>

inherit HANDS;

void create()
{
        set_name("金戒指", ({ "golden ring", "ring" }));
        set_weight(400);
        set("unit", "個");
                set("value", 2000);
                set("material", "gold");
                set("armor_prop/armor", 1);
        setup();
}

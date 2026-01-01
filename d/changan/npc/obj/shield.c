//sjield.c

#include <armor.h>

inherit SHIELD;

void create()
{
        set_name("牛皮盾", ({ "leather shield", "shield", "dun" }));
        set_weight(7000);
        set("material", "leather");
                set("unit", "面");
                set("value", 1200);
                set("armor_prop/armor", 5);
                set("armor_prop/defense", 3);

        setup();
}

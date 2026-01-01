//linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("布衣", ({ "linen" }));
        set_weight(3000);
        set("material", "cloth");
                set("unit", "件");
                set("value", 0);
                set("armor_prop/armor", 1);

        setup();
}

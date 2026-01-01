//beixin.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "皮背心", ({ "pi beixin", "beixin" }));
        set_weight(1000);
        set("unit", "件");
                set("value", 4000);
                set("material", "leather");
                set("armor_prop/armor", 6);
        setup();
}

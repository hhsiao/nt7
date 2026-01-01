// hupi.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("虎皮", ({ "hu pi" }) );
        set_weight(20000);
        set("unit", "張");
                set("material", "cloth");
                set("value", 20000);
                set("armor_prop/armor", 10);
        setup();
}

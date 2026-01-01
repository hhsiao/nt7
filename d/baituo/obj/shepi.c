//shepi

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "蛇皮", ({ "she pi", "pi" }) );
        set_weight(1000);
        set("unit", "件");
                set("value",550);
                set("material", "leather");
                set("armor_prop/armor", 10);
        setup();
}

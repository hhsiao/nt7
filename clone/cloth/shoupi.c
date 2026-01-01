// shoupi.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("獸皮", ({"shou pi", "pi", "cloth"}));
        set_weight(4000);
        set("unit", "件");
                set("value", 800);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        setup();
}

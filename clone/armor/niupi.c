// Last Modified by Lonely on May. 25 2001
// niupi.c

#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("牛皮盾", ({"leather shield","shield", "jia", "armor"}));
        set_weight(6000);
        set("unit", "件");
                set("material", "wood");
                set("value", 1000);
                set("armor_prop/armor", 15);
        setup();
}

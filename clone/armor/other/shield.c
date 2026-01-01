// shield.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("盾牌", ({"shield"}));
        set_weight(1000);
        set("material", "wood");
                set("unit", "面");
                set("armor_prop/armor", 5);
        setup();
}

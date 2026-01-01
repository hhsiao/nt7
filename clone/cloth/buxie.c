// buxie.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("圓口布鞋", ({"yuankou buxie", "bu xie", "shoes"}));
        set_weight(800);
        set("unit", "雙");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        setup();
}

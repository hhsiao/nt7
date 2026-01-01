// cloudshoe.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("踏雲靴", ({ "tayun xue", "cloudy shoes", "shoes" }) );
        set_weight(1700);
        set("unit", "雙");
                set("value", 4500);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 10);
        setup();
}

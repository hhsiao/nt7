// tiejia.c 鐵甲
//

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("鐵甲", ({ "armor" }) );
        set_weight(20000);
        set("unit", "件");
                set("material", "steel");
                set("value", 2000);
                set("armor_prop/armor", 20);
        setup();
}

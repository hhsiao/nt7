// xu-cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黃布袈裟", ({ "jia sha", "cloth" }) );
        set_weight(5000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        setup();
}

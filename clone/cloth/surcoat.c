// surcoat.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name("披風", ({ "surcoat", "pi feng" }) );
        set_weight(1600);
        set("unit", "件");
                set("material", "cloth");
                set("value", 100);
                set("armor_prop/armor", 2);
        setup();
}

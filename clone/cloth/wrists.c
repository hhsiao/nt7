// wrists.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit WRISTS;

void create()
{
        set_name("護腕", ({ "wrists" }) );
        set_weight(800);
        set("unit", "只");
                set("material", "copper");
                set("value", 100);
                set("armor_prop/armor", 2);
        setup();
}

// belt.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit WAIST;

void create()
{
        set_name("腰帶", ({ "yao dai", "belt" }) );
        set_weight(800);
        set("unit", "個");
                set("material", "leather");
                set("value", 100);
                set("armor_prop/armor", 2);
        setup();
}

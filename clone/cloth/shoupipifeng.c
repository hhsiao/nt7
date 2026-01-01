// shoupipifeng.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name("獸皮披風", ({"shoupi pifeng", "pifeng", "cloth"}));
        set_weight(4500);
        set("long", "一件獸皮披風。\n");
                set("material", "leather");
                set("unit", "件");
                set("value", 700);
                set("armor_prop/armor", 35);
        setup();
}

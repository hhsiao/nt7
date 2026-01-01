// shoupiqun.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("獸皮裙", ({"shoupi qun", "cloth"}));
        set_weight(3000);
        set("long", "一條獸皮裙。\n");
                set("material", "leather");
                set("unit", "條");
                set("value", 300);
                set("armor_prop/armor", 15);
        setup();
}

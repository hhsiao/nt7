// taijicloth.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("太極道袍", ({"taiji daopao", "cloth", "pao"}));
        set_weight(2000);
        set("long",
"一件道士穿的長袍，中有太極八卦，左右繡有日月乾坤．\n");
                set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 4);
                set("armor_prop/spells", 5);
}

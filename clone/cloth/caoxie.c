// caoxie.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("草鞋", ({ "cao xie", "xie", "shoes" }) );
        set_weight(900);
        set("long", "一雙鄉下人穿的草鞋．\n");
                set("material", "wood");
                set("unit", "雙");
                set("value", 10);
        setup();
}

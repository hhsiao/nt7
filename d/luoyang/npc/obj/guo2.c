#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIM "橘子" NOR, ({ "juzi" }) );
        set_weight(100);
        set("unit", "個");
                set("value", 50);
                set("food_remaining", 1);
                set("food_supply", 5);
            setup();
}

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIG "大青菜" NOR, ({"qing cai", "qing", "cai"}));
        set_weight(100);
        set("long", "新鮮的青菜。\n");
                set("unit", "棵");
                set("value", 2);
                set("food_remaining", 1);
                set("food_supply", 5);
        setup();
}

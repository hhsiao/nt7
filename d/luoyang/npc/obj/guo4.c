#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create() {
    set_name(HIR "荔枝" NOR, ({ "lizhi" }) );
    set_weight(100);
    set("unit", "串");
    set("value", 50);
    set("food_remaining", 1);
    set("food_supply", 5);
    setup();
}

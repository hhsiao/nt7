#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create() {
    set_name(HIG "蘋果" NOR, ({ "pingguo" }) );
    set_weight(100);
    set("unit", "個");
    set("value", 50);
    set("food_remaining", 1);
    set("food_supply", 5);
    setup();
}

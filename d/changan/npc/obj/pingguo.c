//pingguo.c

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("蘋果", ({"ping guo", "pingguo", "guo"}));
    set_weight(80);
    set("long", "一個大蘋果。n");
    set("unit", "個");
    set("value", 100);
    set("food_remaining", 3);
    set("food_supply", 20);
}

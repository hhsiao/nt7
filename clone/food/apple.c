inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("蘋果", ({"ping guo", "apple", "pingguo"}));
    set_weight(40);
    set("long", "又大又脆的青蘋果。\n");
    set("unit", "顆");
    set("value", 50);
    set("food_remaining", 4);
    set("food_supply", 30);
}

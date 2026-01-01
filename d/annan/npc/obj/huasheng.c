
inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("花生", ({"hua sheng", "hua", "sheng"}));
    set_weight(100);
    set("long", "這是一碟五香花生。\n");
    set("unit", "碟");
    set("value", 80);
    set("food_remaining", 10);
    set("food_supply", 20);
}

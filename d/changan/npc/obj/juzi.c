//juzi.c

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("桔子", ({"ju zi", "juzi", "zi"}));
    set_weight(80);
    set("long", "一個黃橙橙的桔子。n");
    set("unit", "個");
    set("value", 100);
    set("food_remaining", 4);
    set("food_supply", 20);
}

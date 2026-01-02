// mian.c

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("面", ({ "mian" }));
    set_weight(100);
    set("long", "一碗熱氣騰騰的麵條。\n");
    set("unit", "碗");
    set("value", 50);
    set("food_remaining", 1);
    set("food_supply", 50);
    setup();
}

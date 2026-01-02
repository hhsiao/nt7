inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("狗肉", ({ "gou rou", "rou" }));
    set_weight(300);
    set("long", "一塊香噴噴的狗肉。\n");
    set("unit", "塊");
    set("value", 200);
    set("food_remaining", 4);
    set("food_supply", 50);
}

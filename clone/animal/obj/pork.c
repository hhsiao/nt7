// pork.c 豬肉
// Last Modified by Lonely on Aug. 1 2002

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("小豬耳朵", ({"zhu erduo", "zhu rou", "pork"}));
    set_weight(300);
    set("long", "一塊小豬耳朵肉。\n");
    set("unit", "塊");
    set("value", 80);
    set("food_remaining", 4);
    set("food_supply", 20);
}

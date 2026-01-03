// turou.c 野兔肉

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("兔肉", ({"tu rou", "tu"}));
    set_weight(300);
        set("long", "一塊鮮血淋漓肥的野兔肉。\n");
        set("unit", "塊");
        set("value", 200);
        set("food_remaining", 4);
        set("food_supply", 50);
}

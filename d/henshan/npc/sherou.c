inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("蟒蛇肉", ({"she rou", "she"}));
    set_weight(3000);
        set("long", "一大塊蟒蛇肉。\n");
        set("unit", "塊");
        set("value", 500);
        set("food_remaining", 25);
        set("food_supply", 50);
}

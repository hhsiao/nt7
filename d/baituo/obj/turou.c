// turou.c

inherit F_FOOD;
inherit ITEM;

void create() {
    set_name("兔肉", ({ "tu rou", "rou" }) );
    set_weight(300);
    set("long", "一隻燒烤得香香的兔肉。\n");
    set("unit", "只");
    set("value", 50);
    set("food_remaining", 3);
    set("food_supply", 25);
    setup();
}

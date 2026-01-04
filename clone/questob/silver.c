// silver.c

inherit COMBINED_ITEM;

void create() {
    set_name("銀器", ({ "silverware", "yin qi", "silver" }));
    set("long", "這是一個銀製的餐具。\n");
    set("base_unit", "個");
    set("base_weight", 10000);
    set("no_sell", 1);
    set("unit", "些");

    set_amount(1);
    setup();
}

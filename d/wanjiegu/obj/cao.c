// cao.c

inherit ITEM;

void create() {
    set_name("藥草", ({ "cao" }) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("unit", "堆");
    set("no_shown", 1);
    set("no_get", 1);
    set("long", "這是一堆藥草。\n");
    set("value", 1);
}

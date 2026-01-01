//key.c
inherit ITEM;
void create() {
    set_name("柴", ({ "chai"}));
    set_weight(3000);
    set("unit", "捆");
    set("long", "這是一捆木柴。\n");
    set("value", 0);
    set("material", "wood");
}

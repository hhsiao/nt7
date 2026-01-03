// corn.c

inherit ITEM;

void create() {
    set_name("石臼", ({ "mortar" }) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("unit", "只");
    set("no_shown", 1);
    set("no_get", 1);
    set("long", "這是一用來煉藥用的石臼。\n");
    set("value", 1);
}

//ken 1999.12.11
inherit ITEM;
void create() {
    set_name("風燈", ({ "風燈", "deng" }) );
    set_weight(500);
    set_max_encumbrance(80000);
    set("no_get", 1);
    set("no_shown", 1);
        set("unit", "盞");
        set("long", "水晶玻璃的風燈。\n");
        set("value", 1);
}

int is_container() { return 1; }

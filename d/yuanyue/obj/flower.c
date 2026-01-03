inherit ITEM;

void create() {
    set_name("野花", ({ "flower" , "野花" }) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    set("unit", "叢");
    set("long", "一叢不知名的野花，靜靜地綻放。\n");
    set("value", 1);

}

int is_container() { return 1; }

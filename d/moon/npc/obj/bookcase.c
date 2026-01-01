//ken 1999.12.11
inherit ITEM;
void create()
{
        set_name("書櫃", ({ "書櫃", "bookcase"}) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        set("no_shown", 1);
        set("unit", "個");
                set("long", "一個小書櫃。\n");
                set("value", 1);
}

int is_container() { return 1; }

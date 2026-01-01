inherit ITEM;
void create()
{
        set_name("麻布袋", ({ "budai", "dai", "bag" }));
        set_weight(0);
        set_max_encumbrance(100000000000000);
        set("unit", "個");
                set("long", "一隻用麻布織成的袋子，好像可以裝東西。\n");
                set("value", 100);
                set("no_steal",1);
}

int is_container() { return 1; }

int no_limit_amount() { return 1; }

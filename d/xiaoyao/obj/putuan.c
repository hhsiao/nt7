// putuan.c 小蒲團

inherit ITEM;

void create()
{
        set_name("小蒲團", ({ "putuan", "pu", "tuan" }));
        set_weight(500);
        set_max_encumbrance(10000);
        set("unit", "個");
                set("long", "一個普通的小蒲團。\n");
                set("value", 100);
}

int is_container() { return 1; }

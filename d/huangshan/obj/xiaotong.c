// xiaotong.c

inherit ITEM;

void create()
{
        set_name("童子", ({ "tong zi","tong", "zi" }) );
        set_weight(500);
        set_max_encumbrance(800);
        set("no_get", 1);
        set("no_shown", 1);
        set("unit", "個");
                set("long", "一塊恰如跪拜的童子小石。\n");
                set("value", 1);
}

int is_container() { return 1; }

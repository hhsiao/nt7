// tangquan.c

inherit ITEM;

void create() {
    set_name("湯泉", ({ "tang quan", "tang", "quan" }) );
    set_weight(500);
    set_max_encumbrance(8000);
    set("no_get", 1);
    set("no_shown", 1);
    set("unit", "個");
    set("long", "一個已經乾涸了的泉孔。\n");
    set("value", 1);
}

int is_container() { return 1; }

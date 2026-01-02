//key.c
inherit ITEM;
void create() {
    set_name("鑰匙", ({ "key"}));
    set_weight(100);
    set("unit", "把");
    set("long", "這是一把普通的銅鑰匙。\n");
    set("value", 0);
    set("material", "iron");
}

// baijinhe.c

inherit ITEM;

void create() {
    set_name("白金鶴", ({ "baijin he", "he" }));
    set_weight(1800);
    set("unit", "只");
    set("long", "這是一亮晶晶的金屬鶴形飾物，看起來比銀子要亮一些。\n");
    set("value", 2000);
    set("material", "platina");
    setup();
}

// jinyt.c

inherit ITEM;

void create() {
    set_name("金硯臺", ({ "jin yantai", "yantai" }));
    set_weight(1500);
    set("unit", "座");
    set("no_sell", "這...這是什麼東西？我可不敢要。\n");
    set("long", "一座純金的硯臺，入手非常的沉重。\n");
    set("value", 1);
    set("material", "gold");
    setup();
}

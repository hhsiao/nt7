// yuping.c

inherit ITEM;

void create() {
    set_name("玉瓶", ({ "yu ping", "ping" }));
    set_weight(700);
    set("unit", "只");
    set("long", "這是一隻玉瓶，玲瓏精緻。\n");
    set("value", 1500);
    set("material", "jade");
    setup();
}

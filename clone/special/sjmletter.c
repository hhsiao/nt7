// bufa.c
inherit ITEM;

void create() {
    set_name("商劍鳴親筆書信", ({ "sjm letter", "letter" }));
    set_weight(200);
    set("unit", "封");
    set("long", "這是商劍鳴的親筆書信，上書「尊師王維揚親啟」。\n");
    set("value", 100);
    set("no_sell", 1);
    set("material", "paper");
}

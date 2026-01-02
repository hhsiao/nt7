#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create() {
    set_name(HIW "鋼劍" NOR, ({ "gang jian", "sword", "jian" }));
    set_weight(10000);
    set("unit", "柄");
    set("long", "一柄鋒利的長劍。\n");
    set("value", 500);
    set("material", "gold");
    init_sword(20);
    setup();
}

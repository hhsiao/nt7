#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create() {
    set_name("大刀", ({ "da dao", "dao", "blade" }));
    set_weight(10000);
    set("unit", "柄");
    set("long", "一柄鋒利的大刀。\n");
    set("value", 1000);
    set("material", "gold");
    init_blade(10);
    setup();
}

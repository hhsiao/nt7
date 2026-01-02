#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create() {
    set_name(HIW "孤星劍" NOR, ({ "guxing jian", "guxing", "jian", "sword" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 300000);
    set("material", "steel");
    init_sword(50);
    setup();
}

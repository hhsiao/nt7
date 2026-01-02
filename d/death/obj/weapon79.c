#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create() {
    set_name(HIC "吳鉤劍" NOR, ({ "wugou jian", "wugou", "jian", "sword" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 400000);
    set("material", "steel");
    init_sword(60);
    setup();
}

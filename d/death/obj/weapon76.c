#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create() {
    set_name(MAG "古松殘钁" NOR, ({ "gusong jian", "gusong", "jian", "sword" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 1000000);
    set("material", "steel");
    init_sword(90);
    setup();
}

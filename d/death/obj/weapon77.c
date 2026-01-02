#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create() {
    set_name(YEL "吳陽劍" NOR, ({ "wuyang jian", "wuyang", "jian", "sword" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 900000);
    set("material", "steel");
    init_sword(80);
    setup();
}

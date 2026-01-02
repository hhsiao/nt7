#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
    set_name(HIY "赤金刀" NOR, ({ "chijin dao", "chijin", "blade", "dao" }));
    set_weight(5000);
    set("unit", "柄");
    set("value", 200000);
    set("material", "steel");
    init_blade(80);
    setup();
}

void owner_is_killed() {
    destruct(this_object());
}

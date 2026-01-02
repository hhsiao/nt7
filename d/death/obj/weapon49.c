#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create() {
    set_name(HIY "金陽神刀" NOR, ({ "jinyang dao", "jinyang", "blade", "dao" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 1400000);
    set("material", "steel");
    init_blade(120);
    setup();
}

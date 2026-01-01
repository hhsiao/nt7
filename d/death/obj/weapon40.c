#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC "缺月刃" NOR, ({ "queyue ren", "queyue", "ren", "blade", "dao" }) );
        set_weight(4000);
        set("unit", "根");
                set("value", 240000);
                set("material", "steel");
        init_blade(50);
        setup();
}

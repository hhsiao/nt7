#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIY "齊王天刀" NOR, ({ "qiwang dao", "qiwang", "blade", "dao" }) );
        set_weight(4000);
        set("unit", "根");
                set("value", 300000);
                set("material", "steel");
        init_blade(55);
        setup();
}

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(CYN "蟬翼刀" NOR, ({ "chanyi dao", "chanyi", "blade", "dao" }) );
        set_weight(4000);
        set("unit", "根");
                set("value", 250000);
                set("material", "steel");
        init_blade(50);
        setup();
}

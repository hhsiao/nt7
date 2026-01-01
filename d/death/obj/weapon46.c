#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC "青雕玉琢" NOR, ({ "qingyu dao", "qingyu", "blade", "dao" }) );
        set_weight(4000);
        set("unit", "柄");
                set("value", 1000000);
                set("material", "steel");
        init_blade(80);
        setup();
}

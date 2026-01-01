#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIR "盤龍杖" NOR, ({ "panlong zhang", "zhang", "panlong", "staff" }) );
        set_weight(8000);
        set("unit", "根");
                set("value", 250000);
                set("material", "steel");
        init_staff(50);
        setup();
}

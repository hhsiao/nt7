#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name( WHT "枯骨刀" NOR, ({ "blade" }));
        set_weight(300);
        set("unit", "把");
                set("value", 30);
                set("material", "leather");
        init_blade(250);
        setup();
}
void owner_is_killed()
{
        destruct(this_object());
}

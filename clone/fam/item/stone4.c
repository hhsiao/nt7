#include <ansi.h>
#include "stone.h"

void create()
{
        set_name(HIM "輝石" NOR, ({ "hui shi", "hui", "shi" }));
        set("base_unit", "顆");
                set("base_value", 180000);
                set("base_weight", 100);
        setup();
}

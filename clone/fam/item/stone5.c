#include <ansi.h>
#include "stone.h"

void create()
{
        set_name(HIG "輝月華石" NOR, ({ "hua shi", "hua", "shi" }));
        set("base_unit", "顆");
                set("base_value", 500000);
                set("base_weight", 100);
        setup();
}

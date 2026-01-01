#include <ansi.h>
#include "stone.h"

void create()
{
        set_name(HIY "嵐石" NOR, ({ "lan shi", "lan", "shi" }));
        set("base_unit", "顆");
                set("base_value", 50000);
                set("base_weight", 100);
        setup();
}

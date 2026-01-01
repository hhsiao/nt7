#include <ansi.h>
#include "stone.h"

void create()
{
        set_name(HIW "皓石" NOR, ({ "hao shi", "hao", "shi" }));
        set("base_unit", "顆");
                set("base_value", 100000);
                set("base_weight", 100);
        setup();
}

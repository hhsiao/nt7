#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name("蛇皮", ({ "she pi", "she", "pi" }));
        set("long", NOR + RED "巨蟒的皮革，質地堅韌，頗為罕見。\n" NOR);
                set("base_unit", "張");
                set("base_value", 4000);
                set("base_weight", 600);
        setup();
        set_amount(1);
}

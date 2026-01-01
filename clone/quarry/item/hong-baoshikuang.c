#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "紅寶石礦" NOR, ({ "hong baoshikuang", "hong" }));
        set("base_unit", "塊");
                set("unit", "塊");
                set("base_value", 10000);
                set("base_weight", 600);
        setup();
}
int query_autoload()
{
        return 1;
}

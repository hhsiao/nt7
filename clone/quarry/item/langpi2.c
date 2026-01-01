#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIW "銀狼皮" NOR, ({ "yinlang pi", "yinlang", "pi" }));
        set("long", HIW "銀狼的皮毛，革毛具佳，頗為罕見，非常"
                            "之名貴。\n" NOR);
                set("base_unit", "張");
                set("base_value", 12000);
                set("base_weight", 300);
        setup();
        set_amount(1);
}

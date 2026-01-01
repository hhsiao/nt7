inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG "碧水融華" NOR, ({"bishui ronghua" }));
        set_weight(2000);
        set("unit", "顆");
                set("value", 500000);
                set("enchase/name", "碧水融華");
                set("enchase/point", 120);
                set("enchase/type", "wrists");
                                set("enchase/cur_firm", 100);
                                set("enchase/spe_data", ([]) );
        setup();
}

int query_autoload()
{
        return 1;
}

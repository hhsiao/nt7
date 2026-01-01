inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY "鷹眼" NOR, ({"ying yan" }));
        set_weight(2000);
        set("unit", "顆");
                set("value", 500000);
                set("enchase/name", "鷹眼");
                set("enchase/point", 120);
                set("enchase/type", "wrists");
                                set("enchase/cur_firm", 90);
                                set("enchase/spe_data", ([]) );
        setup();
}

int query_autoload()
{
        return 1;
}

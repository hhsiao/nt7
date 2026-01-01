inherit TESSERA;
#include <ansi.h>

void create()
{
        set_name(HIC "真武寶石" NOR, ({"zhenwu baoshi", "zhenwu", "baoshi" }));
        set_weight(2000);
        set("unit", "顆");
                set("value", 500000);
                set("enchase/name", "真武寶石");
                set("enchase/point", 1000);
                set("enchase/type", "weapon");
                set("can_be_qiling", 1);
        setup();
}

int query_autoload()
{
        return 1;
}

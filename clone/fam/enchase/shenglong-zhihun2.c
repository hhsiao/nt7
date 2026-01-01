#include <ansi.h>
inherit TESSERA;

void create()
{
        set_name(HIW "聖龍之魂" NOR, ({"shenglong zhihun", "zhihun" }));
        set_weight(2000);
        set("unit", "顆");
                set("value", 500000);
                set("enchase/name", "聖龍之魂");
                set("enchase/point", 1);
                set("enchase/type", "head");
                set("can_be_qiling", 1);
        setup();
}

int query_autoload()
{
        return 1;
}

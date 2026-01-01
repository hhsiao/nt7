#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "火鳳凰之角" NOR, ({ "phoenix horn", "horn" }));
        set_weight(3000);
        set("long", HIR "一根火鳳凰之角，通體深紅。\n" NOR);
                set("unit", "根");
                set("value", 500000);
        setup();
}

int query_autoload()
{
        return 1;
}

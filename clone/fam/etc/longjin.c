#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIW "龍筋" NOR, ({ "dragon vein", "vein" }));
    set_weight(2000);
    set("long", HIW "一根龍筋，閃閃發光。\n" NOR);
    set("unit", "根");
    set("value", 400000);
    setup();
}

int query_autoload() {
    return 1;
}

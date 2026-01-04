#include <ansi.h>
inherit TESSERA;

void create() {
    set_name(HIR "赤煉虎膽" NOR, ({"chilian hudan", "chilian", "hudan" }));
    set_weight(2000);
    set("unit", "顆");
    set("value", 500000);
    set("enchase/name", "赤煉虎膽");
    set("enchase/point", 1000);
    set("enchase/type", "weapon");
    set("can_be_qiling", 1);
    setup();
}

int query_autoload() {
    return 1;
}

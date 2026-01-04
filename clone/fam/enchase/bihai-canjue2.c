#include <ansi.h>
inherit TESSERA;

void create() {
    set_name(HIG "碧海殘钁" NOR, ({"bihai canjue", "bihai", "canjue" }));
    set_weight(1000);
    set("unit", "顆");
    set("value", 500000);
    set("enchase/name", "碧海殘钁");
    set("enchase/point", 5);
    set("enchase/type", "waist");
    set("can_be_qiling", 1);
    setup();
}

int query_autoload() {
    return 1;
}

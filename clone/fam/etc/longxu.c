#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIW "龍須" NOR, ({ "dragon beard", "beard" }));
    set_weight(1000);
    set("long", HIW "一根龍王的鬍鬚。\n" NOR);
    set("unit", "根");
    set("value", 500000);
    setup();
}

int query_autoload() {
    return 1;
}

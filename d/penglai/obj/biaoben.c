#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIM "蝴蝶標本" NOR, ({ "hudie biaoben" }) );
    set_weight(100);
    set("unit", "個");
    set("value", 1);
    set("long", HIM "這是蝶仙用死去的蝴蝶做成的標本。\n" NOR);

    setup();
}

int query_autoload() {
    return 1;
}

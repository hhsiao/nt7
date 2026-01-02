#include <ansi.h>

inherit ITEM;

void create() {
    set_name(HIC "鮮花" NOR, ({ "flower" }) );
    set_weight(3);
    set("long", "一朵鮮花。\n");
    set("unit", "朵");
    set("value", 0);
    setup();
}

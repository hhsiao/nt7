#include <ansi.h>
inherit ITEM;

void create() {
    set_name(HIW "獨角獸之角" NOR, ({ "unicorn horn", "unicorn", "horn" }));
    set_weight(1000);
    set("long", HIW "獨角獸的角，似乎可以賣個好價錢。\n" NOR);
    set("unit", "根");
    set("value", 700000);
    setup();
}

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create() {
    set_name(HIW "玉斧" NOR, ({ "yu fu", "yu", "fu" }));
    set_weight(500);
    set("unit", "柄");
    set("long", HIW "一柄用白玉做成的斧頭，相當的精美。\n" NOR);
    set("value", 5000);
    set("material", "jade");
    init_hammer(10);
    setup();
}

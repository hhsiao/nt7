#include <ansi.h>

#include <weapon.h>

inherit HAMMER;

void create() {
    set_name(HIY"天羅錘"NOR, ({ "tianluo chui", "chui", "tianluo", "hammer" }) );
    set_weight(18000);
    set("unit", "把");
    set("value", 250000);
    set("material", "steel");
    init_hammer(50);
    setup();
}

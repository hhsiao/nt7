#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create() {
    set_name(WHT "餛飩靈索" NOR, ({ "huntun suo", "huntun", "suo", "whip" }) );
    set_weight(4000);
    set("unit", "根");
    set("value", 1200000);
    set("material", "steel");
    init_whip(90);
    setup();
}

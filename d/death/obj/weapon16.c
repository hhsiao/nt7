#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create() {
    set_name(HIR "八仙杖" NOR, ({ "baxian zhang", "zhang", "baxian", "staff" }) );
    set_weight(13000);
    set("unit", "根");
    set("value", 1400000);
    set("material", "steel");
    init_staff(100);
    setup();
}

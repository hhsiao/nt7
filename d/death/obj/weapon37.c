#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create() {
    set_name(WHT "魚腸劍" NOR, ({ "yuchang dagger", "dagger", "yuchang" }) );
    set_weight(4000);
    set("unit", "柄");
    set("value", 2000000);
    set("material", "steel");
    init_dagger(100);
    setup();
}

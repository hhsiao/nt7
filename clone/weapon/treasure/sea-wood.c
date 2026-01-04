// sea-wood.c 南海神木
// Last Modified by Lonely on Sep. 7 2001

#include <ansi.h>;
#include <weapon.h>;
inherit SWORD;
inherit F_UNIQUE;

void create() {
    set_name(HIC"南海神木"NOR, ({ "sea wood", "wood", "sword" }));
    set_weight(2000);
    set("unit", "根");
    set("long", "這是一根遍體發出青光的劍形木棍。\n");
    set("value", 2000);
    set("material", "wood");
    set("wield_msg", "$N從背後將南海神木拔出來，拿在手中。\n");
    set("unwield_msg", "$N將手中的$n重新插回背後。\n");
    init_sword(100);
    setup();
}

// mugun.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit STICK;

void create() {
    set_name("木棍", ({"bang"}));
    set_weight(1400);
    set("unit", "根");
    set("value", 100);
    set("material", "wood");
    set("wield_msg", "$N「呼」地一聲抽出一把$n握在手中。\n");
    init_stick(15);
    setup();
}

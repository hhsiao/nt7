// shuzhi.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit STICK;

void create() {
    set_name("樹枝", ({"shuzhi"}));
    set_weight(7000);
    set("unit", "把");
    set("material", "wood");
    init_stick(8);
    setup();
}

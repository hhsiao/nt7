// gucui.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit HAMMER;

void create() {
    set_name("鼓錘", ({"guchui", "hammer"}));
    set_weight(200);
    set("unit", "個");
    init_hammer(1);
    setup();
}

// kouzi.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit THROWING;

void create() {
    set_name("銅釦", ({"kouzi"}));
    set("long", "一枚小銅釦");
    set("unit", "些");
    set("base_unit", "枚");
    set("base_weight", 40);
    set("base_value", 0);
    set_amount(1);
    init_throwing(20);
    setup();
}

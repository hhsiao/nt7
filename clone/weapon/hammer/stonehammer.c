// stonehammer.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit HAMMER;

void create() {
    set_name("石鎖", ({"stone hammer", "stone", "hammer"}));
    set_weight(5000);
    set("unit", "個");
    set("long", "一把沉重的石鎖。\n");
    init_hammer(25);
    setup();
}

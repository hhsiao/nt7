// panguanbi.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit SWORD;

void create() {
    set_name("判官筆", ({"panguanbi", "sword"}));
    set_weight(1000);
    set("unit", "雙");
    set("value", 300);
    init_sword(20);
    setup();
}

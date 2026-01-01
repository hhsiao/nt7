// kandao.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("砍刀", ({ "blade" }) );
   set_weight(2000);
        set("long",
"一把大砍刀．\n");
                set("unit", "把");
                set("value", 1000);
                set("material","wood");
        init_blade(20);
        setup();
}

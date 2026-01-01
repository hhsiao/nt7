// shawei.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit STICK;

void create()
{
        set_name("殺威大棒", ({"shawei bang", "bang"}));
        set_weight(3000);
        set("unit", "把");
                set("value", 200);
                set("material", "wood");
        init_stick(20);
        setup();
}

// wuchangbang.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit STICK;

void create()
{
        set_name("無常棒", ({"wuchang bang", "bang"}));
        set_weight(5000);
        set("long", "一把精巧的短棒，一頭是白色，一頭是黑色。\n");
                set("unit", "根");
                set("material", "steel");
                set("wield_msg", "$N陰笑一聲，手裡已多了一把$n。\n");
                set("value", 3000);
        init_stick(40);
        setup();
}

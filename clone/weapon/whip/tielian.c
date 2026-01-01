// tielian.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("鐵鏈", ({"tie lian", "lian", "whip"}));
        set_weight(2000);
        set("long","一條長長的鐵鏈，上面沾滿了血．\n");
                set("unit", "條");
                set("value", 500);
        init_whip(25);
        setup();
}

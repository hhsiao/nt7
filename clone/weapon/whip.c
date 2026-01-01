// whip.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("皮鞭", ({"pi bian", "pibian", "bian", "whip"}));
        set_weight(1000);
        set("long","一條長長的皮鞭．\n");
                set("unit", "條");
                set("value", 500);
        init_whip(15);
        setup();
}

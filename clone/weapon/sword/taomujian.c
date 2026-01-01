// taomujian.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("桃木劍", ({"taomu jian", "sword", "jian"}));
        set_weight(1000);
        set("long","一把桃木製成的長劍，一般是用來寫咒畫符的．\n");
                set("unit", "把");
                set("value", 200);
        init_sword(5);
        setup();
}

// biyuqiang.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("碧玉雙槍", ({ "jade spear", "spear" }));
        set_weight(10000);
        set("unit", "杆");
                set("long","一對玉製的青色短槍，象是有錢人家的擺設，卻又鋒利無比．\n");
                set("value", 9000);
                set("material", "blacksteel");
                set("wield_msg","$N雙手一分，從背後解下一對短槍握到手中．\n");
                set("unwield_msg", "$N將手中的$n繫到背後．\n");
        init_spear(20);
        setup();
}

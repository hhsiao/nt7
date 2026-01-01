// gangzhang
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("鋼杖", ({"gang zhang", "zhang", "staff"}));
        set_weight(6000);
        set("unit", "把");
                set("value", 300);
                set("material", "steel");
                set("long", "這是一鋼製的杖．\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N將手中的$n插入腰後．\n");
        init_staff(35);
        setup();
}

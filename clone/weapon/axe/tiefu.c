// tiefu.c
// Last Modified by Lonely on May. 25 2001

#include <weapon.h>
inherit AXE;

void create()
{
         set_name("鐵斧", ({ "lumber axe", "axe" }) );
         set_weight(22000);
         set("unit", "把");
                 set("long", "這是一把沉重的鐵斧，用來砍柴。\n");
                 set("value", 300);
                 set("wield_msg", "$N拿出一把砍柴用的$n，握在手中當作武器。\n");
                 set("unwield_msg", "$N放下手中的$n。\n");
         init_axe(10);
         setup();
}

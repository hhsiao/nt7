// weapon: tiegun.c

#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("鐵棍", ({ "tiegun", "gun" }) );
        set_weight(1500);
        set("unit", "根");
                set("long", "這是一根渾鐵棍，似乎威力不大。\n");
                set("value", 1000);
                set("material", "iron");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");

        init_club(100);
        setup();
}

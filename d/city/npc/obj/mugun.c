// mugun.c 木棍

#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("木棍", ({ "mugun", "gun" }) );
        set_weight(350);
        set("long", "一根削得很精緻的短棍。\n");
                set("unit", "根");
                set("value", 100);
                set("wield_msg", "$N抓起一根$n，握在手中當武器。\n");
                set("material", "wood");
        init_club(1);
        setup();
}

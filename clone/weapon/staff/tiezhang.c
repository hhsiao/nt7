// tiezhang.c
// Last Modified by Lonely on May. 25 2001

#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( "鐵杖", ({ "tie zhang", "zhang", "staff" }) );
        set_weight(8000);
        set("unit", "條");
                set("long", "一條沉重的鐵杖。\n");
                set("value", 1000);
                set("no_sell",1);
                set("material", "steel");

        init_staff(20);
        setup();
}

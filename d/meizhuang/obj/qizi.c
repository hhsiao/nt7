#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(CYN "棋子" NOR, ({ "qi zi", "qi", "zi" }) );
        set("unit", "些");
                set("value", 0);
                set("base_unit", "顆");
                set("base_weight", 1);
                set("base_value", 0);
                set("material", "iron");
        set_amount(40);
        init_throwing(10);
        setup();
}

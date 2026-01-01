#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIW "鎖鏈" NOR, ({ "suo lian", "suo", "lian" }));
        set_weight(300);
        set("unit", "根");
                set("value", 30);
                set("material", "leather");
        init_whip(50);
        setup();
}

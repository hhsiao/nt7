#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name( "打鐵錘",  ({ "hammer" }));
        set_weight(10000);
        set("unit", "柄");
                set("long", "一柄普通的打鐵錘。\n");
                set("value", 1000);
                set("material", "gold");
        init_hammer(10);
        setup();
}

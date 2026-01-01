//laofang-key.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "牢房鑰匙" NOR, ({"laofang key", "key"}));
        set_weight(100);
        set("unit", "把");
                set("long", "一把牢房鑰匙。\n");

        set("is_monitored", 1);
        setup();
}

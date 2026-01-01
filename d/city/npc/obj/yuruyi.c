// yuruyi.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT"玉如意"NOR, ({ "yu ruyi", "ruyi" }) );
        set_weight(50);
        set("long", "玉如意。\n");
                set("unit", "個");
                set("value", 200000 );

}

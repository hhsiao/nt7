// biyu.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG"碧玉"NOR, ({ "bi yu", "yu" }) );
        set_weight(100);
        set("long", "一塊碧綠如緞的玉。\n");
                set("unit", "塊");
                set("value", 80000 );

}

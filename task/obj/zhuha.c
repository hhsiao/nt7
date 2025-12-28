#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIG "莽牯朱蛤" NOR,({ "zhu ha" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "wood");
                set("long", "這是一個莽牯朱蛤。\n");
        }
        set("owner", "段譽");
        setup();
}


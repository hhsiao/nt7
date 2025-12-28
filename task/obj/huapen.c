#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIG "精緻花盆" NOR,({ "hua pen" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "stone");
                set("long", "這是一個精緻花盆。\n");
        }
        set("owner", "華赫艮");
        setup();
}


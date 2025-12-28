#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIC "青花瓷花瓶" NOR,({ "hua ping" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "stone");
                set("long", "這是一個青花瓷花瓶。\n");
        }
        set("owner", "劉掌櫃");
        setup();
}


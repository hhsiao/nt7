#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "蒙汗藥" NOR,({ "menghan yao" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "包");
                set("material", "wood");
                set("long", "這是一包蒙汗藥。\n");
        }
        set("owner", "韋小寶");
        setup();
}  

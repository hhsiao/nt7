#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIR "陰陽合歡散" NOR,({ "yinyang hehuansan" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "包");
                set("material", "wood");
                set("long", "這是一包陰陽合歡散。\n");
        }
        set("owner", "段延慶");
        setup();
}  

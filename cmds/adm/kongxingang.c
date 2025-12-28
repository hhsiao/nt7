#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIK "鐵皮空心缸" NOR,({ "kongxin gang" }) ); 
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "cloth");
                set("long", "這是一個鐵皮空心缸。\n");
        }
        set("owner", "裘千丈");
        setup();
}


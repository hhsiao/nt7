#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIY "黃金杵" NOR,({ "huangjin chu" }) ); 
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "把");
                set("material", "cloth");
                set("long", "這是一把黃金杵。\n");
        }
        set("owner", "達爾巴");
        setup();
}


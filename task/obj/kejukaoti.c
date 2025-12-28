#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIR "科舉考題" NOR,({ "keju kaoti" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "paper");
                set("long", "這是一個科舉考題。\n");
        }
        set("owner", "考官");
        setup();
}


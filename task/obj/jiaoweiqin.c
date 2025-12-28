#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIM "焦尾琴" NOR,({ "jiaowei qin" }) ); 
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "張");
                set("material", "wood");
                set("long", "這是一張焦尾琴。\n");
        }
        set("owner", "何足道");
        setup();
}


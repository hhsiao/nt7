#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "玲瓏骰子" NOR,({ "linglong touzi" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "stone");
                set("long", "這是一個玲瓏骰子。\n");
        }
        set("owner", "莊家");
        setup();
}


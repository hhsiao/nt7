#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "尚方寶劍" NOR,({ "shangfang baojian" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "個");
                set("material", "stone");
                set("long", "這是一個尚方寶劍。\n");
        }
        set("owner", "段正淳");
        setup();
}


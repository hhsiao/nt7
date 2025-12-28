#include <ansi.h>
inherit TASK;
void create()
{
        set_name(YEL "鵝黃色百褶裙" NOR,({ "baizhe qun" }) ); 
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "件");
                set("material", "cloth");
                set("long", "這是一件鵝黃色百褶裙。\n");
        }
        set("owner", "苗若蘭");
        setup();
}


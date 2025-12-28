#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "軟蝟甲" NOR,({ "ruanwei jia" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "件");
                set("material", "silk");
                set("long", "這是一件軟蝟甲。\n");
        }
        set("owner", "黃蓉");
        setup();
}


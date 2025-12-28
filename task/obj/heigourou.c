#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIW "烏龜狗香香" NOR,({ "hei gourou" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "份");
                set("material", "wood");
                set("long", "這是一份烏龜狗香香。\n");
        }
        set("owner", "楊小邪");
        setup();
}


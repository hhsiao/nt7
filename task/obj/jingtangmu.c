#include <ansi.h>
inherit TASK;
void create()
{
        set_name(HIC "驚堂木" NOR,({ "jingtang mu" }) );
        set_weight(100);
        if( clonep() )
                destruct(this_object());
        else {
                set("unit", "根");
                set("material", "wood");
                set("long", "這是一根驚堂木。\n");
        }
        set("owner", "包拯");
        setup();
}


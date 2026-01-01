#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BLU"熊掌"NOR, ({"xiong zhang"}));
        set("unit", "只");
                set("long", "這是一隻黑熊掌。\n");
                set("yaowang", 1);
                set("value", 1000);
                set("weight", 1000);
        setup();
}

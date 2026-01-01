// nixie.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
        set_name( HIC "青布尼鞋" NOR, ({ "ni xie", "xie" }) );
        set_weight(1000);
        set("unit", "雙");
                set("long", "一雙青布尼鞋。\n");
                set("value", 0);
                set("material", "boots");
                set("armor_prop/dodge", 5);
                set("female_only", 1);
        setup();
}

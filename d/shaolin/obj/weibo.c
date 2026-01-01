#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name( HIC "圍脖" NOR, ({ "wei bo", "bo" }) );
        set_weight(500);
        set("unit", "條");
                set("long", "這是一皮圍脖，用以保護頸部。\n");
                set("value", 100);
                set("material", "neck");
                set("armor_prop/armor", 3);
                set("shaolin",1);
        setup();
}

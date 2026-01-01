#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "鐵甲", ({ "armor", "tiejia" }) );
        set_weight(1000);
        set("unit", "件");
                set("value", 4000);
                set("material", "leather");
                set("armor_prop/armor", 10);
        setup();
}

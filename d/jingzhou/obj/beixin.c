#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "皮背心", ({ "beixin", "pi beixin" }) );
        set_weight(1000);
        set("unit", "件");
                set("value", 2000);
                set("material", "leather");
                set("armor_prop/armor", 6);
        setup();
}

// heiyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("黑色長衫", ({ "chang shan", "cloth" }) );
        set_weight(2000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}

// qingduanao.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"青緞襖"NOR, ({"qingduan ao", "ao", "cloth"}));
        set_weight(3000);
        set("unit", "件");
                set("value", 250);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        setup();
}

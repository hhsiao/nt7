// p_jiasha.c 紫色袈裟
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( MAG "紫色袈裟" NOR ,({"jiasha","jia sha","cloth"}));
        set_weight(5000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 200);
                set("value",100);
        setup();
}

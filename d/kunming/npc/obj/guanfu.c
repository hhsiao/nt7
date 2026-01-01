// guanfu.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name( HIC "官服" NOR, ({ "guan fu", "fu" }) );
        set_weight(3000);
        set("unit", "件");
                set("material", "絲");
                set("value", 5000);
                set("armor_prop/armor", 3);
        setup();
}

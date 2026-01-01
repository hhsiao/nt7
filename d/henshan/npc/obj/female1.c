#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG "湖綠長裙" NOR, ({ "green skirt", "cloth" }) );
        set_weight(3000);
        set("unit", "件");
                set("long", "一件清新可人的湖綠長裙。\n");
                set("material", "cloth");
                set("value", 0);
                set("armor_prop/armor", 3);
                set("female_only", 1);
        setup();
}

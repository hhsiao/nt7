#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIG "綠衫" NOR, ({ "lv shan", "lv", "shan", "cloth" }));
        set_weight(3000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}

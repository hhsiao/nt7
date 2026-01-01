#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(CYN "黑衣"NOR, ({ "cloth" }) );
        set_weight(3000);
        set("long","這是一件繡著紅色火焰的黑色聖衣。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        setup();
}

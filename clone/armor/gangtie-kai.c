// tiejia.c 鐵甲
//

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(NOR + WHT "鋼鐵鎧" NOR, ({ "gangtie kai", "gangtie", "kai" }) );
        set_weight(30000);
        set("unit", "件");
                set("material", "steel");
                set("value", 300000);
                set("armor_prop/armor", 300);
        setup();
}

int query_autoload()
{
        return 1;
}

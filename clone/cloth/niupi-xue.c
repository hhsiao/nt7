// niupi-xue.c

#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("牛皮靴", ({"niupi xie", "xie", "shoes"}));
        set_weight(800);
        set("unit", "雙");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        setup();
}

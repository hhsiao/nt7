// shuikao.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("夜行水靠", ({"Shui kao", "kao" }) );
        set_weight(1000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        setup();
}

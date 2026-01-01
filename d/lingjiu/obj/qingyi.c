//qingyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("青衣", ({"qing yi", "cloth","yi"}) );
    set_weight(2000);
    set("unit", "件");
                set("long", "這是件質量上佳青衣，是由[針神]親手縫製的。\n");
        set("material", "cloth");
        set("armor_prop/armor", 10);
        set("value",100);
    setup();
}

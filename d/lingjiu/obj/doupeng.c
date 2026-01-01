//doupeng.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("斗篷", ({"dou peng", "peng"}) );
    set_weight(2000);
    set("unit", "件");
        set("long", "這是件斗篷。\n");
        set("material", "cloth");
        set("armor_prop/armor", 10);
        set("value",100);
    setup();
}

// junfu.c

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("軍服", ({ "junfu", "cloth" }));
        set("long", "這是一件有點舊的官兵服。\n");
        set_weight(2000);
        set("material", "cloth");
                set("unit", "件");
                set("value", 200);
                set("armor_prop/armor", 10);
        setup();
}

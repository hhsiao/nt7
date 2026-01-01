// Room: /d/kunlun/npc/obj/goupi.c
// Last Modified by Lonely on Jun. 29 2001

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("狗皮", ({ "gou pi", "pi" }) );
        set_weight(5000);
        set("unit", "塊");
                set("material", "fur");
                set("value", 300);
                set("armor_prop/armor", 1);
        setup();
}

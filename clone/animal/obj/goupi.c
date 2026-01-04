// goupi.c
// Last Modified by Lonely on Aug. 1 2002

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(YEL"狗皮"NOR, ({ "gou pi", "pi" }) );
    set_weight(5000);
    set("unit", "塊");
    set("material", "fur");
    set("value", 100);
    set("armor_prop/armor", 1);
    setup();
}

#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create() {
    set_name(HIC"緬甸翡翠指環"NOR, ({ "zhihuan" }) );
    set_weight(100);
    set("material", "鐵");
    set("unit", "枚");
    set("value", 6000);
    set("armor_prop/armor", 16);
    set("armor_prop/dodge", 12);
    setup();
}

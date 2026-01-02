#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create() {
    set_name(MAG"紫袍"NOR, ({ "zi pao", "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("value", 200);
    set("material", "cloth");
    set("armor_prop/armor", 5);
    setup();
}

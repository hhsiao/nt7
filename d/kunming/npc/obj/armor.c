#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name("鐵甲", ({ "armor", "jia" }) );
    set_weight(28000);
    set("unit", "件");
    set("value", 4000);
    set("material", "leather");
    set("armor_prop/armor", 25);
    setup();
}

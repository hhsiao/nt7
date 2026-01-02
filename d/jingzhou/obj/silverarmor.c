#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name("亮銀甲", ({ "silverarmor", "yinarmor", "yinjia" }) );
    set_weight(30000);
    set("unit", "件");
    set("value", 10000);
    set("material", "leather");
    set("armor_prop/armor", 45);
    setup();
}

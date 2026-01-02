#include <armor.h>
inherit CLOTH;

void create() {
    set_name("金邊黑布袈裟", ({ "jia sha", "cloth" }) );
    set_weight(5000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 10);
    setup();
}

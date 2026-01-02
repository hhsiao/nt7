#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(HIW "二品侍衛裝" NOR, ({ "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("long", "御前侍衛的統一裝束。\n");
    set("value", 1000);
    set("material", "cloth");
    set("armor_prop/armor", 25);
    setup();
}

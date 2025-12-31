#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(HIY "雕龍長袍" NOR, ({ "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("value", 6000);
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

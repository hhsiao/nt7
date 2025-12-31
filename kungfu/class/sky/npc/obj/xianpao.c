#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(HIW "仙袍" NOR, ({ "xian pao" }) );
    set_weight(1000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

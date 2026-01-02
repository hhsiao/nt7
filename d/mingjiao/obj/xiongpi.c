#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create() {
    set_name(HIW"熊皮"NOR, ({ "xiong pi", "pi" }) );
    set_weight(9000);
    set("unit", "塊");
    set("material", "fur");
    set("value", 30000);
    set("warm_cloth", 1);
    set("armor_prop/armor", 80);
    setup();
}

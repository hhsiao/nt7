#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create() {
    set_name(HIC"安南戰靴"NOR, ({ "boot" }) );
    set_weight(100);
    set("material", "皮革");
    set("unit", "雙");
    set("value", 3000);
    set("armor_prop/armor", 100);
    set("armor_prop/dodge", 6);
    setup();
}

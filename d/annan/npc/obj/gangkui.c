#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create() {
    set_name(HIB"藤盔"NOR, ({ "tengkui" }) );
    set_weight(1000);
    set("material", "鐵");
    set("unit", "件");
    set("value", 1500);
    set("armor_prop/armor", 30);
    set("armor_prop/dodge", 11);
    setup();
}

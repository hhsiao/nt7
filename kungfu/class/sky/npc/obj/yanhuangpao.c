#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(HIY "炎黃聖袍" NOR, ({ "yanhuang shengpao" }) );
    set_weight(1000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

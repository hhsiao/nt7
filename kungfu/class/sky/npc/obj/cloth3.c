#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(HIB "青色長衫" NOR, ({ "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

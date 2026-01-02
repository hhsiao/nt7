#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create() {
    set_name(HIW "銀甲" NOR, ({ "armor" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 100);
    setup();
}
void owner_is_killed() {
    destruct(this_object());
}

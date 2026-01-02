// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
    set_name(HIC "頭盔" NOR, ({ "tou kui", "kui" }) );
    set_weight(500);
    set("unit", "頂");
    set("long", "這是一頂金屬頭盔，用以保護頭部。\n");
    set("value", 100);
    set("material", "head");
    set("armor_prop/armor", 10);
    set("shaolin", 1);
    setup();
}

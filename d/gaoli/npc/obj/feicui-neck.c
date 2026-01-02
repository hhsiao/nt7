#include <armor.h>
#include <ansi.h>

inherit NECK;

void create() {
    set_name(HIG"翡翠項鍊"NOR, ({ "necklace" }) );
    set_weight(1000);
    set("long", "這是一串名貴的翡翠項鍊。\n");
    set("material", "翡翠");
    set("unit", "串");
    set("value", 1000);
    set("armor_prop/armor", 10);
    set("armor_prop/dodge", 2);
    set("armor_prop/per", 5);
    setup();
}

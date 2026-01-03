// sengmao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create() {
    set_name(HIR "僧帽" NOR, ({ "seng mao", "mao" }) );
    set_weight(500);

    set("unit", "頂");
    set("long", "這是一頂藏僧戴的僧帽。\n");
    set("value", 100);
    set("material", "head");
    set("armor_prop/armor", 10);
    set("xueshan", 1);
    setup();
}

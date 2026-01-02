// guazi.c

#include <armor.h>
inherit CLOTH;

void create() {
    set_name("對衿褂子", ({ "duijin guazi" }));
    set("long", "這是一件少數民族常用的對衿褂子。\n");
    set_weight(2000);
    set("material", "cloth");
    set("unit", "件");
    set("value", 350);
    set("armor_prop/armor", 5);
    setup();
}

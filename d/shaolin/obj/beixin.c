// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name("鐵背心", ({ "tie beixin", "beixin" }) );
    set_weight(3000);
    set("unit", "件");
    set("value", 0);
    set("material", "cloth");
    set("armor_prop/armor", 15);
    set("shaolin", 1);
    setup();
}

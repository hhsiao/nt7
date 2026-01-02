//ring.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create() {
    set_name(MAG"紫金戒指"NOR, ({ "zijin jiezhi", "jiezhi", "ring" }));
    set("weight", 100);
    set("unit", "個");
    set("value", 1000);
    set("material", "gold");
    set("armor_prop/armor", 1);

    setup();
}

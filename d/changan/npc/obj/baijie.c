//baijie.c

#include <armor.h>

inherit HANDS;

void create()
{
        set_name("白金戒指", ({ "bai jie", "baijie", "ring" }));
        set("weight", 400);
        set("unit", "個");
                set("value", 10000);
                set("material", "gold");
                set("armor_prop/armor", 1);
                set("armor_prop/per", 1);
        setup();
}

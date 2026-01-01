// zhenzhu.c 珍珠
#include <armor.h>

inherit HEAD;

void create()
{
        set_name("大珍珠", ({ "zhenzhu" }) );
        set_weight(8000);
        set("material", "cloth");
                set("unit", "個");
                set("long", "這是一個大珍珠，很值錢。\n");
                set("value", 30000);
                set("armor_prop/dodge", 5);
        setup();
}

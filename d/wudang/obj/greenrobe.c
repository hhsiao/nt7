// greenrobe.c 青色道袍
// By Marz

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("青色道袍", ({"pao", "cloth", "dao pao"}) );
    set_weight(1500);
    set("female_only", 1);
        set("unit", "件");
                set("long", "這是件質地輕軟的青色道袍，邊上還鏤著花呢。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    setup();
}

// black_cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("夜行布衣", ({ "black cloth", "cloth" }) );
        set_weight(3000);
        set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        setup();
}

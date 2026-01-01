// magua.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("馬褂", ({ "ma gua", "gua", "cloth"}));
        set_weight(3000);
        set("long", "一件淡青色的馬褂．\n");
                set("unit", "件");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 5);
        setup();
}

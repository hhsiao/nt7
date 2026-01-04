// zhanpao.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit CLOTH;

void create() {
    set_name("戰袍", ({"zhan pao", "pao", "cloth"}));
    set_weight(4000);
    set("long", "一件戰袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
    set("armor_prop/armor", 30);
    setup();
}

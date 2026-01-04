// sengxie.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
inherit BOOTS;

void create() {
    set_name("僧鞋", ({ "seng xie", "xie" }) );
    set_weight(1000);
    set("unit", "雙");
    set("long", "一雙圓口青布僧鞋。");
    set("value", 100);
    set("material", "boots");
    set("armor_prop/dodge", 3);
    setup();
}

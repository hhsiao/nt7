// maxie.c  麻鞋

#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("麻鞋", ({"ma xie", "xie", "shoes"}));
        set_weight(1000);
        set("long", "一雙麻繩編制的鞋子。\n");
                set("unit", "雙");
                set("value", 5);
                set("material", "silk");
                set("armor_prop/armor", 1);
        setup();
}

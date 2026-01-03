#include <armor.h>

inherit BOOTS;

void create()
{
       set_name("僧鞋", ({ "seng xie", "xie" }) );
       set_weight(1000);
               set("unit", "雙");
               set("long", "一雙青布僧鞋");
               set("value", 30);
               set("material", "boots");
               set("armor_prop/dodge", 1);
       setup();
}

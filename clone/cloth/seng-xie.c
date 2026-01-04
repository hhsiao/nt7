// seng-xie.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create() {
    set_name(HIC "僧鞋" NOR, ({ "seng xie", "xie" }) );
    set_weight(1000);
    set("unit", "雙");
    set("long", "一雙出家人用的青布僧鞋。\n");
    set("value", 0);
    set("material", "boots");
    set("armor_prop/dodge", 5);
    setup();
}

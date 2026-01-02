// huyao.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create() {
    set_name("鐵護腰", ({ "hu yao", "huyao" }) );
    set_weight(500);
    set("unit", "條");
    set("long", "這是一件皮質的護腰，上面滿布鐵釘，用以保護腰部。\n");
    set("value", 6000);
    set("material", "waist");
    set("armor_prop/armor", 5);
    set("shaolin", 1);
    setup();
}

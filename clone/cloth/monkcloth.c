// monkcloth.c
// Last Modified by Lonely on May. 25 2001

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create() {
    set_name(HIY"護法袈裟"NOR, ({ "hufa jiasha", "jiasha", "cloth" }) );
    set_weight(3000);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 15);
    setup();
}

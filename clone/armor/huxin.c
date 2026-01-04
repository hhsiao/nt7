// huxin.c
// Last Modified by Lonely on May. 29 2001

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
    set_name("護心", ({ "hu xin", "huxin" }) );
    set_weight(500);
    set("unit", "雙");
    set("long", "這是一件鐵質的護心，用以保護心部。\n");
    set("value", 6000);
    set("material", "wrists");
    set("armor_prop/armor", 5);
    set("shaolin", 1);
    setup();
}

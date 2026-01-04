// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ITEM;

void create() {
    set_name("碎片", ({ "piece" }) );
    set_weight(1000);
    set("unit", "堆");
    set("long", "一堆不知道什麼東西的碎片。\n");
    setup();
}

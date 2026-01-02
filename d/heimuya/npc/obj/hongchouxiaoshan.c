// hongchouxiaoshan.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create() {
    set_name("紅綢小杉", ({ "cloth" }) );
    set_weight(5000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

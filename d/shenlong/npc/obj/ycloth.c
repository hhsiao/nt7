// ycloth.c
//
// This is the basic equip for players just login.

#include <armor.h>;
#include <ansi.h>;
inherit CLOTH;

void create() {
    set_name(HIY"黃布衣"NOR, ({ "yellow cloth", "cloth" }) );
    set_weight(3000);
    set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    setup();
}

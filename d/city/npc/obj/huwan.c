// huwan.c 護腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create() {
    set_name("護腕", ({ "wrists", "hu wan", "huwan" }) );
    set_weight(500);
    set("unit", "雙");
    set("long", "這是一件布質的護腕，用以保護腕部。\n");
    set("value", 1300);
    set("material", "cloth");
    set("armor_prop/armor", 5);
    setup();
}

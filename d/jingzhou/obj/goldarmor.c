#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name("黃金甲", ({ "goldarmor", "jinarmor", "jinjia" }) );
    set_weight(35000);
    set("unit", "件");
    set("value", 20000);
    set("material", "leather");
    set("armor_prop/armor", 50);
    setup();
}

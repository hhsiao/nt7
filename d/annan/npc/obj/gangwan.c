#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create() {
    set_name(HIG"鋼腕"NOR, ({ "gangwan" }) );
    set_weight(300);
    set("material", "鐵");
    set("unit", "副");
    set("value", 3000);
    set("armor_prop/armor", 38);
    //set("armor_prop/dodge",-1);
    setup();
}

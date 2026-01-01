#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create() {
    set_name(HIG"安南腰帶"NOR, ({ "yaodai" }) );
    set_weight(800);
    set("material", "鐵");
    set("unit", "副");
    set("value", 3000);
    set("armor_prop/armor", 38);
    //set("armor_prop/dodge",-1);
    setup();
}

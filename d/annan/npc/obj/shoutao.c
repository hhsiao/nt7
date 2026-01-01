#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create() {
    set_name(HIC"安南手套"NOR, ({ "shoutao" }) );
    set_weight(100);
    set("material", "鐵");
    set("unit", "枚");
    set("value", 3000);
    set("armor_prop/armor", 32);
    //set("armor_prop/dodge",2);
    setup();
}

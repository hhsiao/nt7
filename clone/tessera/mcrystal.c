// mcrystal.c 神之水晶

#include <ansi.h>
#include <armor.h>

inherit TESSERA;

void create() {
    set_name(HIM "神之水晶" NOR, ({ "magic crystal" }) );
    set_weight(50);
    set("long", HIM "一塊閃爍這奇異光芒的粉色水晶，"
        "讓人感到一陣陣的心悸。\n" NOR);
    set("value", 200000);
    set("unit", "塊");
    set("level", 4);
    set("no_identify", 1);
    setup();
}

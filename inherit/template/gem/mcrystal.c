// mcrystal.c 神之水晶

#include <ansi.h>

inherit TESSERA;

void create()
{
        set_name(HIM "神之水晶" NOR, ({ "magic crystal" }) );
        set_weight(50);
        set("long", HIM "一塊閃爍這奇異光芒的粉色水晶，"
                    "讓人感到一陣陣的心悸。\n" NOR);
                set("value", 200000);
                set("unit", "塊");
                set("can_be_tessera", 1);
                set("level", 4);
                set("material", "mcrystal");
                set("magic/type", "magic");
                set("magic/power", 500);
                set("auto_load", 1);
        set("enchase/weapon_prop/add_magic", 3);
        set("enchase/rings_prop/add_magic", 3);
        set("enchase/armor_prop/reduce_magic", 1);
        setup();
}

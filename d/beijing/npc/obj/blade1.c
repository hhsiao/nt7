#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name( HIW "鋼刀" NOR,  ({ "gang dao", "dao", "blade" }));
        set_weight(10000);
        set("unit", "柄");
                set("long", "一柄鋼鐵打造的刀。\n");
                set("value", 500);
                set("material", "gold");
        init_blade(20);
        setup();
}

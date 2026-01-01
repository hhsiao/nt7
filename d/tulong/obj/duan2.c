#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(CYN "斷了的屠龍刀" NOR, ({ "duan dao" , "blade" , "dao"}) );
        set_weight(30000);
        set("unit", "柄");
                set("long", "一柄斷了的刀。\n");
                set("value", 0);
                set("rigidity",8000);
                set("material", "steel");
        init_blade(1);
        setup();
}

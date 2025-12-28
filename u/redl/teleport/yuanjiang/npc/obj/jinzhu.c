// This program is a part of NITAN MudLIB 
// redl 2015/10
#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(NOR YEL "金蛛" NOR, ({"jin zhu", "jin", "zhu" }));
                set("long", "這是隻休眠著的異種生物，驅使方法可能要去哀牢山問大顛上人了。\n");
                set("unit", "只");
                set("value", 10000000);
                set("base_value", 10000000);
                set("base_unit", "只");
                set("base_weight", 1000000);
                set("is jin zhu", 1);
        setup();
}


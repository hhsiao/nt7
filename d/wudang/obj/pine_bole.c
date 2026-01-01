// pine_bole.c 紅松樹幹
// Last Modified by Lonely on Aug. 18 2002

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"紅松樹幹"NOR,({ "bole", "pine bole" }));
        set_weight(3000);
        set("long", "這是一根紅松樹幹，是製造香火的好材料。\n");
                set("unit", "根");
                set("value", 100);
                set("material", "wood");
                set("self_destruct", 1);
        setup();
}
int value()
{
        return 1;
}

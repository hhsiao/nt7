// Food: songguo.c
// Last Modified by Lonely on Aug. 18 2002

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIG"野松果"NOR, ({"guo", "song guo"}));
        set_weight(40);
        set("long", "一顆從林子裡採來的野松果。\n");
                set("unit", "顆");
                set("value", 60);
                set("food_remaining", 3);
                set("food_supply", 30);
}

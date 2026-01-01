// This program is a part of NITAN MudLIB
// redl 2012/12/1
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"麻薯"NOR, ({"ma shu", "ma"}));
        set_weight(20);
        set("long", "一個糯米包著紅豆沙作成的麻薯，好香啊。\n");
                set("unit", "個");
                set("value", 10000);
                set("food_remaining", 20);
                set("food_supply", 1);
}


int finish_eat()
{
                message_vision(NOR + CYN + "$N" + NOR + CYN + "吃完" + query("name") + NOR + CYN + "，心滿意足地咂咂嘴，真的好好吃啊……\n" NOR, this_player());
                return 0;
}

// wandouhuang.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;
void create()
{
        set_name(HIY"豌豆黃"NOR, ({"wandou huang", "huang"}));
        set_weight(80);
        set("unit", "塊");
                set("value", 80);
                set("food_remaining", 5);
                set("food_supply", 8);
}

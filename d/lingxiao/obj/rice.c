inherit ITEM;
inherit F_FOOD;

#include <ansi.h>

void create()
{
        set_name(HIW "珍珠飯" NOR, ({ "rice", "fan" }) );
        set("long", "一碗用雪山珍珠米作的飯。\n");
                set("unit", "碗");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
                set("material", "rice");
        setup();
}

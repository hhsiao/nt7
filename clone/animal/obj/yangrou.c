// yangrou.c 烤羊腿
// Last Modified by Lonely on Aug. 1 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("烤羊腿", ({"kao yangtui", "yangtui"}));
        set_weight(300);
        set("long", "一隻烤得香噴噴的羊腿。\n");
                set("unit", "只");
                set("value", 100);
                set("food_remaining", 4);
                set("food_supply", 60);
}

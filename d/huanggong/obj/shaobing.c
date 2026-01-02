// shaobing.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>;
void create() {
    set_name(YEL"肉末燒餅"NOR, ({"roumo shaobing", "bing"}));
    set_weight(80);
    set("unit", "只");
    set("value", 100);
    set("food_remaining", 10);
    set("food_supply", 5);
}

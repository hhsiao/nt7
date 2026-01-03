// huotui.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create() {
    set_name(RED"櫻桃火腿"NOR, ({ "yingtao huotui", "huotui" }) );
    set("long", "一盆香噴噴熱氣騰騰的櫻桃火腿。\n");
    set("unit", "盆");
    set("value", 200);
    set("food_remaining", 10);
    set("food_supply", 20);
    set("material", "meat");
    setup();
}

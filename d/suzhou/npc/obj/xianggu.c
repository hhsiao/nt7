// huotui.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create() {
    set_name(YEL"清炒香菇"NOR, ({ "qingchao xianggu", "xianggu" }) );
    set("long", "一碟香噴噴的清炒香菇。\n");
    set("unit", "碟");
    set("value", 120);
    set("food_remaining", 10);
    set("food_supply", 25);
    set("material", "meat");
    setup();
}

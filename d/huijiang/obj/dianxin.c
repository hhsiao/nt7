// Room: /d/huijiang/obj/dianxin.c
// Last Modified by Lonely on Sep. 12 2001

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("點心", ({"dian xin", "dianxin"}));
    set_weight(40);
    set("long", "一碟香噴噴的點心，還冒著熱氣.\n");
    set("unit", "碟");
    set("value", 80);
    set("food_remaining", 4);
    set("food_supply", 30);
}

//bao1.c

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("豬肉包子", ({"zhurou baozi", "baozi"}));
    set_weight(80);
    set("long", "一個香噴噴、熱騰騰的豬肉灌湯包。\n");
    set("unit", "個");
    set("value", 25);
    set("food_remaining", 2);
    set("food_supply", 40);
}

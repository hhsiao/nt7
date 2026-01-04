// yougao.c

inherit ITEM;
inherit F_FOOD;

void create() {
    set_name("千層油糕", ({ "qianceng yougao", "yougao" }) );
    set_weight(50);     //一兩
    set("unit", "個");
    set("value", 40);
    set("food_remaining", 1);
    set("food_supply", 40);
    setup();
}

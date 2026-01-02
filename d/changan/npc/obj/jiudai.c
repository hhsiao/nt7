//jiudai.c

inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("牛皮酒袋", ({"jiudai", "niupi", "skin"}));
    set_weight(700);
    set("long", "一個用來裝竹葉青酒的大酒袋，大概裝得八、九升的酒。\n");
    set("unit", "個");
    set("value", 100);
    set("max_liquid", 15);
    set("liquid", ([
        "type": "alcohol",
        "name": "竹葉青酒",
        "remaining": 15,
        "drunk_apply": 5
        ]));
}

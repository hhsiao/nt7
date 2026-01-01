inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("牛皮酒袋", ({"jiudai"}));
    set_weight(700);
    set("long", "一個用來裝米酒的大酒袋，大概裝得八、九升的酒。\n");
    set("unit", "個");
    set("value", 20);
    set("max_liquid", 15);

    set("liquid", ([
        "type": "alcohol",
        "name": "米酒",
        "remaining": 15,
        "drunk_supply": 6
        ]));
}

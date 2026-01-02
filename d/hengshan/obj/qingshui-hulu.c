// qingshui-hulu.c
// Last Modified by Sir on May. 22 2001

inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("清水葫蘆", ({"qingshui hulu", "hulu", "bottle"}));
    set_weight(700);
    set("long", "一個用葫蘆製成的水壺。\n");
    set("unit", "個");
    set("value", 100);
    set("max_liquid", 10);

    // because a container can contain different liquid
    // we set it to contain water at the beginning
    set("liquid", ([
        "type": "water",
        "name": "清水",
        "remaining": 10,
        "drunk_supply": 10
        ]));
}

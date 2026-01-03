// hulu.c

inherit ITEM;
inherit F_LIQUID;

void create() {
    set_name("葫蘆", ({"hulu", "hu"}));
    set_weight(700);
    set("long", "一個用葫蘆製成的水壺。\n");
    set("unit", "個");
    set("value", 100);
    set("max_liquid", 10);
    set("liquid", ([
        "type": "water",
        "name": "清水",
        "remaining": 10,
        "drunk_supply": 10
        ]));
}
